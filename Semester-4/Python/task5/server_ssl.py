import socket
import ssl

# Buat socket TCP
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('0.0.0.0', 8443))
server_socket.listen(5)

# Konfigurasi SSL
context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
context.load_cert_chain(certfile='cert.pem', keyfile='key.pem')

print("Menunggu koneksi di port 8443...")

try:
    while True:
        try:
            client_socket, addr = server_socket.accept()
            # Bungkus koneksi client dalam SSL
            ssl_client_socket = context.wrap_socket(client_socket, server_side=True)
            print(f"Terhubung dengan {addr}")
            ssl_client_socket.sendall(b"Selamat datang di server SSL!\n")
            ssl_client_socket.close()
        except ssl.SSLError as e:
            print(f"[SSL ERROR] Koneksi dari {addr} ditolak: {e}")
            client_socket.close()
        except Exception as e:
            print(f"[ERROR] Koneksi gagal: {e}")
except KeyboardInterrupt:
    print("\nServer dihentikan oleh user.")
finally:
    server_socket.close()
