#!/usr/bin/env python3
import socket
import os

UPLOAD_DIR = "uploads"
os.makedirs(UPLOAD_DIR, exist_ok=True)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('0.0.0.0', 5001))
server.listen(5)

print("[*] Menunggu koneksi...")

while True:
    client_socket, addr = server.accept()
    print(f"[+] Terhubung dengan {addr}")

    try:
        filename = client_socket.recv(1024).decode()
        print(f"[INFO] Menerima file: {filename}")
        save_path = os.path.join(UPLOAD_DIR, f"received_{filename}")

        with open(save_path, "wb") as f:
            while True:
                bytes_read = client_socket.recv(4096)
                if not bytes_read:
                    break
                f.write(bytes_read)

        print(f"[INFO] File {filename} berhasil disimpan di {save_path}")
        client_socket.send("[Server] File berhasil diterima.".encode())
    except Exception as e:
        print(f"[ERROR] {e}")
        client_socket.send(f"[Server] Terjadi kesalahan: {e}".encode())
    finally:
        client_socket.close()
