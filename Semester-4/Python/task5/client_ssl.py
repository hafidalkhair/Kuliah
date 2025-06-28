import socket
import ssl

# Buat context SSL dan set agar percaya pada cert.pem
context = ssl.create_default_context(cafile="cert.pem")

with context.wrap_socket(socket.socket(socket.AF_INET), server_hostname='Hafidl Alkhair') as conn:
    conn.connect(('localhost', 8443))
    print(conn.recv(4096).decode())
