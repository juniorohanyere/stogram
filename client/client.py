import socket

# Create a socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
server_address = ('localhost', 12345)  # Replace with the server's address and port
client_socket.connect(server_address)

# Communication logic
data = client_socket.recv(1024)
print(f"Received message from C: {data.decode()}")

# Close the socket
client_socket.close()
