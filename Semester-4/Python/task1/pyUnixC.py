#!/usr/bin/env python
import sys
from socket import *

class TCPClient:
    def __init__(self):
        self.path = '/tmp/sock'  # Path untuk koneksi ke socket UNIX

    def create(self):
        try:
            self.sockUnix = socket(AF_UNIX, SOCK_STREAM)  # Buat socket UNIX
            self.sockUnix.connect(self.path)  # Hubungkan ke server
            print("Client Message")
            print("--------------")
        except OSError:
            print("Socket error [Pastikan server berjalan dan path benar]")
            sys.exit(1)

    def send(self):
        try:
            while True:
                pesan = input("Pesan : ")  # Meminta input pesan dari pengguna
                if not pesan:
                    break
                self.sockUnix.send(pesan.encode())  # Mengirim pesan ke server
                data = self.sockUnix.recv(1024).decode()  # Menerima respon dari server
                print(f"Respon dari server: {data}")
        except KeyboardInterrupt:
            print("\nClient dihentikan.")
        except Exception as e:
            print(f"Kesalahan terjadi: {e}")
        finally:
            self.__del__()

    def run(self):
        self.create()
        self.send()

    def __del__(self):
        print("Menutup koneksi...")
        self.sockUnix.close()

if __name__ == '__main__':
    client = TCPClient()
    client.run()
