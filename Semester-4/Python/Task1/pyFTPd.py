#!/usr/bin/env python
import os
import sys
import time
import subprocess
from socket import *

# Daftar perintah yang didukung
lstCmd = [
    'dir', 'ls', 'exit', 'bye', 'quit', 'get', 'mget', 'put', 'mput', 'rm', 'delete',
    'mv', 'rename', 'cd', 'pwd', 'chmod', 'cp', 'copy', 'rmdir', 'mkdir', 'close', 'disconnect'
]

# Konfigurasi server
hostIP = '127.0.0.1'
hostPort = 1111
filFlag = '*file*'
getFlag = 'get'


class CMD:
    def __init__(self):
        self.byeFlag = '*bye*'

    def checkCmd(self, cmd):
        ret = ''
        cmd = cmd.strip().split()
        cmd[0] = cmd[0].lower()

        if cmd[0] in lstCmd:
            if cmd[0] in ['ls', 'dir']:
                cmdS = 'ls -al' if len(cmd) == 1 else f'ls {cmd[1]}'
                ret = subprocess.getoutput(cmdS)

            elif cmd[0] in ['rm', 'delete']:
                if len(cmd) == 2:
                    ret = subprocess.getoutput(f'rm {cmd[1]}')
                    ret = f'File {cmd[1]} telah dihapus.' if not ret else ret
                else:
                    ret = 'Penggunaan: rm|delete [file].'

            elif cmd[0] in ['rmdir']:
                if len(cmd) == 2:
                    ret = subprocess.getoutput(f'rm -rf {cmd[1]}')
                    ret = f'Direktori {cmd[1]} telah dihapus.' if not ret else ret
                else:
                    ret = 'Penggunaan: rmdir [direktori].'

            elif cmd[0] in ['mkdir']:
                if len(cmd) == 2:
                    ret = subprocess.getoutput(f'mkdir {cmd[1]}')
                    ret = f'Direktori {cmd[1]} telah dibuat.' if not ret else ret
                else:
                    ret = 'Penggunaan: mkdir [direktori].'

            elif cmd[0] in ['mv', 'rename']:
                if len(cmd) == 3:
                    ret = subprocess.getoutput(f'mv {cmd[1]} {cmd[2]}')
                else:
                    ret = 'Penggunaan: mv|rename [file_lama] [file_baru].'

            elif cmd[0] in ['cp', 'copy']:
                if len(cmd) == 3:
                    ret = subprocess.getoutput(f'cp {cmd[1]} {cmd[2]}')
                else:
                    ret = 'Penggunaan: cp|copy [file_sumber] [tujuan].'

            elif cmd[0] in ['chmod']:
                if len(cmd) == 3:
                    ret = subprocess.getoutput(f'chmod {cmd[1]} {cmd[2]}')
                    ret = f'Hak akses {cmd[1]} telah diubah.' if not ret else ret
                else:
                    ret = 'Penggunaan: chmod [mode] [file].'

            elif cmd[0] in ['cd']:
                if len(cmd) == 2:
                    try:
                        os.chdir(cmd[1])
                        ret = f'Direktori sekarang: {os.getcwd()}'
                    except:
                        ret = 'Direktori tidak ditemukan.'
                else:
                    ret = 'Penggunaan: cd [direktori]'

            elif cmd[0] in ['pwd']:
                ret = f'Direktori sekarang: {subprocess.getoutput("pwd")}'

            elif cmd[0] in ['bye', 'exit', 'quit', 'close', 'disconnect']:
                ret = self.byeFlag

        return ret


class CLI:
    def __init__(self):
        self.cmd = CMD()
        self.childLst = []

    def updatePid(self, pids):
        while self.childLst:
            pid, status = os.waitpid(0, os.WNOHANG)
            if not pid:
                break
            pids.remove(pid)

    def sendFile(self, sock, file):
        sock.send(filFlag.encode())
        user = os.environ['USER']
        size = os.stat(file).st_size
        try:
            with open(file, 'rb') as f:
                sock.send(f"{filFlag}:{file:>214}:{size:>30}:{user:>30}".encode())
                while (buffer := f.read(4096)):
                    sock.send(buffer)
        except:
            return 0
        return 1

    def recvFile(self, sock):
        msg1 = sock.recv(283).decode().split(':')
        flag, namafile, total, user = msg1[0].strip(), msg1[1].strip(), int(msg1[2].strip()), msg1[3].strip()
        pjg = 0

        if flag == filFlag:
            try:
                with open(namafile, 'wb') as f:
                    while pjg < total:
                        msg = sock.recv(4096)
                        pjg += len(msg)
                        f.write(msg)
            except:
                os.remove(namafile)
                return 0
            return 1
        return 0

    def handler(self, sock):
        sock.send("\nSelamat datang di DrSlump FTP Server\n".encode())
        while True:
            data = sock.recv(1024).decode()
            if not data:
                break

            if data.startswith(filFlag):
                ret = self.recvFile(sock)
                sock.send("File telah diterima".encode() if ret else "File gagal diterima".encode())

            elif data.startswith(getFlag):
                cmd = data.strip().split()
                self.sendFile(sock, cmd[1])

            else:
                ret = self.cmd.checkCmd(data)
                if ret == self.cmd.byeFlag:
                    sock.send("Koneksi ditutup...\n".encode())
                    sock.close()
                    break
                sock.send((ret + "\n").encode())

    def runCmd(self):
        print("\n + + + DrSlump FTP Server + + +\n")
        try:
            print("Membuat socket...")
            sockCmd = socket(AF_INET, SOCK_STREAM)
            sockCmd.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            sockCmd.bind((hostIP, hostPort))
            sockCmd.listen(5)
            print(f"Server berjalan di {hostIP}:{hostPort}")
        except Exception as e:
            print(f"Gagal membuat socket: {e}")
            sys.exit(1)

        while True:
            koneksi, alamat = sockCmd.accept()
            self.updatePid(self.childLst)
            pid = os.fork()
            if pid:
                koneksi.close()
                self.childLst.append(pid)
            else:
                sockCmd.close()
                self.handler(koneksi)
                os._exit(0)


if __name__ == "__main__":
    cli = CLI()
    cli.runCmd()
