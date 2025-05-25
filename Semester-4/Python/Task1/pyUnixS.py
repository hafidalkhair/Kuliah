#!/usr/bin/env python
import os
import sys
from socket import *

class TCPServer:
    def __init__(self):
        self.path = '/tmp/sock'  # Path untuk socket UNIX

    def create(self):
        try:
            self.sockUnix = socket(AF_UNIX, SOCK_STREAM)  # Buat socket TCP
            self.sockUnix.bind(self.path)  # Binding alamat
            self.sockUnix.listen(1)  # Listening untuk koneksi
            print("Server Message [tekan Ctrl-C untuk keluar]")
            print("--------------")
        except OSError:
            print(f"Socket sudah digunakan...\n\rJika belum, hapus file {self.path}")
            sys.exit(1)

    def accept(self):
        print("Menunggu koneksi...")
        koneksi, alamat = self.sockUnix.accept()  # Terima koneksi
        print("Ada koneksi...")
        while True:
            try:
                data = koneksi.recv(1024).decode()  # Terima data
                if not data:
                    break
                print(f"Pesan dari client >> {data}")
                koneksi.send(f"[{data}] sudah diterima server.".encode())  # Kirim respon ke client
            except:
                break

    def run(self):
        self.create()
        self.accept()

    def __del__(self):
        print("Menutup server dan menghapus socket...")
        self.sockUnix.close()
        os.system(f'rm -f {self.path}')

if __name__ == '__main__':
    server = TCPServer()
    server.run()
