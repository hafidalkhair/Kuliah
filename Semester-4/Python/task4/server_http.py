#!/usr/bin/env python3
import socket
import os
import mimetypes

# Fungsi untuk membaca file dan menentukan MIME type
def load_file(path):
    try:
        with open(path, 'rb') as f:
            content = f.read()
        content_type = mimetypes.guess_type(path)[0] or 'application/octet-stream'
        header = f"HTTP/1.1 200 OK\r\nContent-Type: {content_type}\r\n\r\n"
        return header.encode() + content
    except FileNotFoundError:
        with open("404.html", "rb") as f:
            content = f.read()
        header = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n"
        return header.encode() + content

# Buat socket TCP
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('0.0.0.0', 8080))
server_socket.listen(5)

print("📡 Server HTTP berjalan di http://localhost:8080 ...")

while True:
    client_socket, addr = server_socket.accept()
    print(f"[+] Terhubung dari {addr}")
    request = client_socket.recv(1024).decode('utf-8')
    print(f"[REQ]\n{request}")

    if not request:
        client_socket.close()
        continue

    # Parsing request
    try:
        filename = request.split()[1]
        if filename == '/':
            filename = '/index.html'
        filepath = filename.lstrip('/')
        response = load_file(filepath)
    except Exception as e:
        print(f"[ERR] {e}")
        response = b"HTTP/1.1 500 Internal Server Error\r\n\r\n<h1>500 Internal Server Error</h1>"

    client_socket.send(response)
    client_socket.close()
