import socket
import binascii

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a specific address and port
server_address = ('localhost', 12345)
server_socket.bind(server_address)

# Listen for incoming connections
server_socket.listen(1)

print("Waiting for a connection...")

# Accept a connection from a client
client_socket, client_address = server_socket.accept()

print(f"Connection established with {client_address}")

try:
    while True:
        # Receive data from the C client
        data = client_socket.recv(1024)
        if not data:
            break  # No more data, exit loop

        received_message = data.decode('utf-8').strip()
        print(f"Received: {received_message}")

        if len(data) != 1 and data != b'\b':
                # Strip newline characters
                data = data.rstrip(b'\n')

        # Convert received data to hexadecimal
        hex_data = binascii.hexlify(data).decode('utf-8')

        # Send the hexadecimal data back to the C client
        client_socket.send(hex_data.encode('utf-8'))
except KeyboardInterrupt:
    pass
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    # Clean up the connection
    client_socket.close()
    server_socket.close()
