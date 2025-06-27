#!/usr/bin/env python3

import socket
import threading

# Konfigurasi Server
IP = '127.0.0.1'
PORT = 3606
MAX_CLIENTS = 5

# Daftar client yang terhubung
clients = []

# Fungsi broadcast pesan ke semua client kecuali pengirim
def broadcast(message, sender_socket):
    for client in clients:
        if client != sender_socket:
            try:
                client.send(message)
            except:
                client.close()
                if client in clients:
                    clients.remove(client)

# Fungsi handle untuk masing-masing client
def handle_client(client_socket, addr):
    print(f"[+] {addr} terhubung.")
    broadcast(f"[INFO] {addr} bergabung ke server.\n".encode('utf-8'), client_socket)

    while True:
        try:
            message = client_socket.recv(1024)
            if not message:
                break
            print(f"[{addr}] {message.decode('utf-8')}")
            broadcast(f"[{addr}] {message.decode('utf-8')}".encode('utf-8'), client_socket)
        except:
            break

    # Jika client keluar
    print(f"[-] {addr} putus koneksi.")
    broadcast(f"[INFO] {addr} keluar dari server.\n".encode('utf-8'), client_socket)
    if client_socket in clients:
        clients.remove(client_socket)
    client_socket.close()

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((IP, PORT))
    server.listen()
    print(f"[*] Server berjalan di {IP}:{PORT}")

    while True:
        client_socket, addr = server.accept()
        if len(clients) < MAX_CLIENTS:
            clients.append(client_socket)
            thread = threading.Thread(target=handle_client, args=(client_socket, addr))
            thread.start()
            print(f"[Aktif] Jumlah koneksi: {len(clients)}")
        else:
            print(f"[!] Menolak {addr}: server penuh.")
            client_socket.send("Server penuh. Silakan coba lagi nanti.\n".encode('utf-8'))
            client_socket.close()

if __name__ == "__main__":
    main()
