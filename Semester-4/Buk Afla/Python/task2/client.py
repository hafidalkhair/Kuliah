#!/usr/bin/env python3
import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 12345))

while True:
    message = input("Ketik pesan: ")
    client.send(message.encode('utf-8'))
    response = client.recv(1024).decode('utf-8')
    print(f"Server: {response}")
