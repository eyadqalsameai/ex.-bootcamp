import socket
import concurrent.futures
def scan_port(host_ip,host_port):
    port_tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    port_tcp.settimeout(1.0)
    try:
        result = port_tcp.connect_ex((host_ip, host_port))
        if result == 0:
            print(f"Port {host_port} is OPEN on {host_ip}")
    finally:
        port_tcp.close()
        
target_ip = input("Enter your ip: ")
print(f"Scanning {target_ip}...")
with concurrent.futures.ThreadPoolExecutor(max_workers=50) as executor:
    for port in range(1, 1025):
        executor.submit(scan_port, target_ip, port)