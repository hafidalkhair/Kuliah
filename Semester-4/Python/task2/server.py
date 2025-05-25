#!/usr/bin/env python3
import socket
import threading

def handle_client(client_socket, addr):
    print(f"[+] Terhubung dengan {addr}")
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            if not message:
                break
            print(f"[{addr}] {message}")
            client_socket.send("Pesan diterima!".encode('utf-8'))
        except:
            break
    print(f"[-] Koneksi dengan {addr} ditutup.")
    client_socket.close()

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('0.0.0.0', 12345))  # Bisa diakses dari semua IP
    server.listen(5)
    print("[*] Server menunggu koneksi...")

    while True:
        client_socket, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(client_socket, addr))
        thread.start()
        print(f"[Aktif] Jumlah koneksi: {threading.active_count() - 1}")

if __name__ == "__main__":
    main()
