#!/usr/bin/env python3
import socket
import sys

# Untuk welcome string
welstr = '\n\rSelamat datang di dr_slump chat server \n\r\
Powered by dr_slump Technology\n\r\n\r\
User Access Verification\n\r\
Password: '

class Net:
    def __init__(self):
        # Cek argumen, jika tidak sama dengan 3
        # tampilkan cara penggunaan
        if len(sys.argv) != 3:
            print("Usage: " + sys.argv[0] + " <hostip> <port>")
            sys.exit(1)
        else:
            self.HOST = sys.argv[1]  # Set nilai host
            self.PORT = int(sys.argv[2])  # Set nilai port
            self.prompt = 'chat> '  # Prompt yang akan ditampilkan

    def Create(self):
        try:
            # Buat socket INET dengan protocol TCP
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        except:
            print("Buat socket error...")
            sys.exit(1)
        else:
            # Binding ip dan port
            s.bind((self.HOST, self.PORT))
            # Mendengarkan koneksi
            s.listen(2)
            print(f"Server listening on {self.HOST}:{self.PORT}...")
            
            # Menerima koneksi yang datang
            koneksi, alamat = s.accept()
            print(f"Connection established with {alamat}")
            # Setelah koneksi diterima, server mengirim pesan selamat datang ke client
            koneksi.send(welstr.encode())
            
            stat = 0  # Flag untuk status koneksi
            # 0=tdk terkoneksi, 1=terkoneksi
            while True:
                # Terima data
                data = koneksi.recv(100).decode()
                if not data:
                    break
                if stat == 0:
                    if data.strip() == "password":
                        stat = 1
                        isi = self.prompt
                        koneksi.send("Anda berhasil login ke server\n\r".encode())
                    else:
                        isi = 'Password: '
                else:
                    if data[:8] == 'hostname':
                        host = data.split(' ')[1]
                        self.prompt = host.strip() + '> '
                        isi = self.prompt
                    elif data.strip() in ['keluar']:
                        koneksi.send("Closing connection...\n".encode())
                        koneksi.close()
                        break
                    else:
                        isi = self.prompt

                print(f"Data diterima: {data}")
                koneksi.send(isi.encode())

            s.close()
            print("Server closed.")

# Inisialisasi dan jalankan server
if __name__ == '__main__':
    net = Net()
    net.Create()
