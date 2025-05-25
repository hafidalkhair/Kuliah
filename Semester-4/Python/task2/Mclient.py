#!/usr/bin/env python3

import socket
import threading

# Konfigurasi Client
SERVER_IP = '127.0.0.1'
SERVER_PORT = 3606

def receive_messages(client):
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            if not message:
                break
            print(message)
        except:
            print("[!] Terputus dari server.")
            client.close()
            break

def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client.connect((SERVER_IP, SERVER_PORT))
    except:
        print("[!] Gagal terhubung ke server.")
        return

    print("[*] Terhubung ke server. Ketik 'exit' untuk keluar.")

    # Thread untuk menerima pesan
    thread = threading.Thread(target=receive_messages, args=(client,))
    thread.start()

    # Kirim pesan
    while True:
        message = input()
        if message.lower() == 'exit':
            break
        try:
            client.send(message.encode('utf-8'))
        except:
            print("[!] Koneksi putus.")
            break

    client.close()

if __name__ == "__main__":
    main()
