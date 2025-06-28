#!/usr/bin/env python
from socket import *
import sys

class TCPServer:
    def __init__(self):
        if len(sys.argv) != 3:
            print('Penggunaan: ' + sys.argv[0] + ' [ip_address] [nomor_port]')
            sys.exit(1)
        else:
            self.HOST = sys.argv[1]
            self.PORT = int(sys.argv[2])

    def Create(self):
        try:
            # Buat socket TCP
            self.sockTCP = socket(AF_INET, SOCK_STREAM)
            # Binding port
            self.sockTCP.bind((self.HOST, self.PORT))
            # Listening
            self.sockTCP.listen(1)
        except Exception as e:
            print(f'Socket error [ip dan port harus valid]: {e}')
            sys.exit()
        else:
            print(f'Server Message [tekan Ctrl-C untuk keluar]')
            print('--------------')
            print(f'Mendengarkan pada port {self.PORT}')

    def Accept(self):
        try:
            koneksi, alamat = self.sockTCP.accept()  # Terima koneksi
            print(f'Koneksi dari {alamat}')
            while True:
                # Lakukukan perulangan selama true
                data = koneksi.recv(1024).decode()  # Decode data yang diterima
                if not data:
                    print('Client disconnected.')
                    break  # Jika client disconnect
                print(f'Pesan dari client >> {data}')  # Cetak pesan client

                if len(data) > 1:
                    # Kirim pesan balik
                    response = f'[{data}] sudah diterima server.'
                    koneksi.send(response.encode())  # Encode sebelum mengirim
        except Exception as e:
            print(f'Error during communication: {e}')
        finally:
            koneksi.close()  # Always close the connection after communication ends

    def Run(self):
        self.Create()
        self.Accept()

    def __del__(self):
        try:
            self.sockTCP.close()  # Tutup koneksi
        except:
            pass

if __name__ == '__main__':
    server = TCPServer()
    server.Run()

