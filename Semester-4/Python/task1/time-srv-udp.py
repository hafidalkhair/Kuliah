#!/usr/bin/env python
import sys
import time
from socket import *

class ServerWaktu:
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
            print("Mengikatkan IP dengan port " + str(self.tHostPort))
            self.tsock.bind(self.tHostPort)
        except Exception as e:
            print("Gagal buat socket: ", e)
            sys.exit(1)
    
    def tungguKoneksi(self):
        print("Menunggu koneksi (Ctrl+C untuk keluar)...")
        while True:
            try:
                data, client = self.tsock.recvfrom(1024)  # Terima data
                print(f"Permintaan diterima dari {client}: {data.decode()}")
                wkt = "Waktu server adalah " + time.ctime(time.time())
                self.tsock.sendto(wkt.encode(), client)  # Kirim waktu ke client
            except KeyboardInterrupt:
                print("Server dihentikan.")
                break
            except Exception as e:
                print("Kesalahan saat menerima data:", e)
    
    def tutupKoneksi(self):
        try:
            print("Tutup koneksi...")
            self.tsock.close()
        except Exception as e:
            print("Gagal menutup koneksi: ", e)
    
    def __del__(self):
        self.tutupKoneksi()

if __name__ == "__main__":
    srv = ServerWaktu()
    srv.buatSocket()
    srv.tungguKoneksi()
