import socket
import time

HOST = '127.0.0.1'  # Localhost
PORT = 9000

def run_test():
    print(f"Attempting to connect to {HOST}:{PORT}...")
    
    try:
        # Create a TCP socket
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((HOST, PORT))
            print("Connected successfully!")
            
            # Send a test payload
            message = "Hello from the Python test script!"
            s.sendall(message.encode('utf-8'))
            print(f"Sent: {message}")
            
            # Briefly pause so you can see it register on the server side
            time.sleep(1)
            
    except ConnectionRefusedError:
        print("Connection failed. Is the server running?")

if __name__ == "__main__":
    run_test()
