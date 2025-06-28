#!/usr/bin/env python
import os
import sys
import string
from socket import *

# Daftar perintah yang didukung
lstCmd = [
    'dir', 'ls', 'exit', 'bye', 'quit', 'clear', 'cls', 'get', 'mget',
    'put', 'mput', 'rm', 'delete', 'mv', 'rename', 'cd', 'pwd', 'chmod',
    'cp', 'copy', '?', 'help', 'rmdir', 'mkdir', '!', 'connect', 'open',
    'close', 'disconnect'
]

defPort = 1111
filFlag = '*file*'

class IO:
    def connect(self, host, port):
        try:
            print('Membuat socket...')
            self.sockIO = socket(AF_INET, SOCK_STREAM)
        except:
            print('Gagal membuat socket!')
            return 0
        
        try:
            print(f'Koneksi ke {host} port {port}')
            self.sockIO.connect((host, port))
        except:
            print('Koneksi gagal!')
            return 0
        
        print('Koneksi sukses...')
        data = self.sockIO.recv(1024).decode()
        print(data)
        return self.sockIO
    
    def sendFile(self, sock, file):
        sock.send(filFlag.encode())
        user = os.environ.get('USER', 'unknown')
        size = os.stat(file).st_size
        
        with open(file, 'rb') as f:
            buffer = f.read(5000000 - 282)
            sock.send(f"{filFlag}:{file:>214}:{str(size).strip():>30}:{user:>30}".encode() + buffer)
            while (buffer := f.read(5000000)):
                sock.send(buffer)
    
    def recvFile(self, sock):
        msg1 = sock.recv(283).decode().split(':')
        flag, namafile, total, user = msg1[0].strip(), msg1[1].strip(), int(msg1[2].strip()), msg1[3].strip()
        
        if flag == filFlag:
            try:
                with open(namafile, 'wb') as f:
                    received = 0
                    while received < total:
                        msg = sock.recv(5000000)
                        received += len(msg)
                        f.write(msg)
                return 1
            except:
                os.remove(namafile)
                return 0
        return 0
    
    def close(self):
        self.sockIO.close()

class CMD:
    def __init__(self):
        self.getFlag = '*get*'
        self.putFlag = '*put*'
        self.IO = IO()
        self.isConnected = 0
    
    def checkCmd(self, cmd):
        cmd0 = cmd.strip()
        cmd = cmd0.split()
        cmd[0] = cmd[0].lower()
        
        if cmd[0] in lstCmd:
            if cmd[0] in ['?', 'help']:
                print('\nDaftar perintah yang tersedia:\n')
                print('? help')
                print('connect [host] | open [host]')
                print('ls [direktori] | dir [direktori]')
                print('cd [direktori]')
                print('get [file] | put [file]')
                print('chmod [mode] [file] | pwd')
                print('mkdir [direktori] | rmdir [direktori]')
                print('rm [file] | delete [file]')
                print('mv [file_lama] [file_baru] | rename [file_lama] [file_baru]')
                print('exit | quit | close | disconnect')
            
            elif cmd[0] in ['connect', 'open']:
                if not self.isConnected:
                    if len(cmd) == 2:
                        self.Sock = self.IO.connect(cmd[1], defPort)
                        self.isConnected = bool(self.Sock)
                    else:
                        print('Penggunaan: connect|open [host]')
                else:
                    print('Tutup koneksi dulu...')
            
            elif cmd[0] in ['clear', 'cls']:
                os.system('clear')
            
            elif cmd[0] == 'put':
                if self.isConnected:
                    if len(cmd) == 2 and os.path.isfile(cmd[1]):
                        self.IO.sendFile(self.Sock, cmd[1])
                    else:
                        print('Gagal membaca file atau format salah.')
                else:
                    print('Penggunaan: put [file]')
            
            elif cmd[0] in ['bye', 'exit', 'quit', 'close', 'disconnect']:
                if self.isConnected:
                    self.Sock.send(cmd[0].encode())
                    print(self.Sock.recv(100).decode())
                    self.isConnected = 0
                else:
                    print('Goodbye...')
                    sys.exit()
            
            elif cmd[0][0] == '!':
                os.system(cmd0[1:])
            
            else:
                try:
                    self.Sock.send(cmd0.encode())
                    return 1
                except:
                    print('Tidak terkoneksi!')
                    return 0
        else:
            print('Perintah tidak dikenal.')
        return 0
    
    def runCmd(self):
        print('\n+ + + DrSlump FTP Client + + +\n')
        while True:
            cmd = input('ftp> ').strip()
            if cmd:
                ret = self.checkCmd(cmd)
                if self.isConnected and ret == 1:
                    data = self.Sock.recv(500000).decode()
                    if data.startswith(filFlag):
                        if self.IO.recvFile(self.Sock) == 0:
                            print('\nFile gagal diunduh!')
                        else:
                            print('\nFile berhasil diunduh...')
                    else:
                        print(data)

if __name__ == "__main__":
    cmd = CMD()
    cmd.runCmd()
