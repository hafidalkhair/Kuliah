#!/usr/bin/env python
import sys
from socket import *

class ClientWaktu:
    def __init__(self):
        if len(sys.argv) != 3:
            print("Penggunaan: " + sys.argv[0] + " <ip_address> <port>")
            sys.exit(1)
        
        self.HOST = sys.argv[1]
        self.PORT = int(sys.argv[2])
        self.tHostPort = (self.HOST, self.PORT)
    
    def buatSocket(self):
        try:
            self.tsock = socket(AF_INET, SOCK_DGRAM)
            print("Menghubungi server waktu di " + str(self.tHostPort))
            self.tsock.sendto(b"Ping", self.tHostPort)  # Kirim string "Ping"
            print("Permintaan terkirim ke server")
        except Exception as e:
            print("Gagal buat socket: ", e)
            sys.exit(1)
    
    def terimaData(self):
        try:
            data, _ = self.tsock.recvfrom(1024)  # Ambil data waktu dari server
            print("Data diterima dari server:", data.decode())
        except Exception as e:
            print("Gagal menerima data: ", e)
    
    def tutupKoneksi(self):
        try:
            print("Tutup koneksi...")
            self.tsock.close()
        except Exception as e:
            print("Gagal menutup koneksi: ", e)
    
    def __del__(self):
        self.tutupKoneksi()

if __name__ == "__main__":
    clt = ClientWaktu()
    clt.buatSocket()
    clt.terimaData()
