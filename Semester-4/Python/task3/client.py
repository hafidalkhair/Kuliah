#!/usr/bin/env python3
import socket
import os
import sys
import time

def print_progress_bar(sent, total, bar_length=40):
    percent = sent / total
    bar = '█' * int(bar_length * percent) + '-' * (bar_length - int(bar_length * percent))
    print(f"\rMengirim: |{bar}| {percent:.0%}", end='')

server_ip = input("Masukkan IP server: ")
server_port = 5001
filename = input("Masukkan nama file yang ingin dikirim: ")

if not os.path.exists(filename):
    print("File tidak ditemukan!")
    sys.exit(1)

filesize = os.path.getsize(filename)
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((server_ip, server_port))

client.send(filename.encode())

sent_bytes = 0
buffer_size = 4096

with open(filename, "rb") as f:
    while True:
        bytes_read = f.read(buffer_size)
        if not bytes_read:
            break
        client.sendall(bytes_read)
        sent_bytes += len(bytes_read)
        print_progress_bar(sent_bytes, filesize)
        time.sleep(0.01)  # biar tampilan smooth

print("\n[INFO] File berhasil dikirim.")

# Terima konfirmasi dari server
response = client.recv(1024).decode()
print(f"Server: {response}")

client.close()
