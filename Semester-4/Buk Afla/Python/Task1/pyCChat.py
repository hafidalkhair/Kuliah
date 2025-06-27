#!/usr/bin/env python
from socket import *
import sys

class TCPClient:
    def __init__(self):
        if len(sys.argv) != 3:
            print('Penggunaan: ' + sys.argv[0] + ' [ip_server] [port]')
            sys.exit(1)
        else:
            self.HOST = sys.argv[1]
            self.PORT = int(sys.argv[2])  # Ensure port is an integer

    def Create(self):
        try:
            self.sockTCP = socket(AF_INET, SOCK_STREAM)  # Buat socket TCP
            self.sockTCP.connect((self.HOST, self.PORT))  # Connect to the server
        except Exception as e:
            print(f'Socket error [ip_server dan port harus valid]: {e}')
            sys.exit()
        else:
            print('Client Message')
            print('--------------')
            print(f'Terhubung ke server {self.HOST}')

    def Send(self):
        try:
            while True:
                pesan = input('Pesan: ')  # Input pesan (raw_input() -> input() in Python 3)
                self.sockTCP.send(pesan.encode())  # Send the message (encode to bytes)
                
                data = self.sockTCP.recv(1024)  # Receive response from the server
                print(f'Pesan dari server: {data.decode()}')  # Decode and print the response
        except KeyboardInterrupt:
            print("\nConnection closed by user.")
        except Exception as e:
            print(f'Error: {e}')
        finally:
            self.__del__()

    def __del__(self):
        if hasattr(self, 'sockTCP'):
            self.sockTCP.close()  # Close the connection

    def Run(self):
        self.Create()
        self.Send()

if __name__ == '__main__':
    client = TCPClient()
    client.Run()
