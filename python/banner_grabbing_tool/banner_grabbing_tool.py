import socket
def grab_banner(ip, port):
    target_tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    target_tcp.settimeout(5.0)
    
    try:
        target_tcp.connect((ip, port))
        if port == 80 or port == 443:
            request = f"GET / HTTP/1.1\r\nHost: {ip}\r\nConnection: close\r\n\r\n"
            target_tcp.send(request.encode())
        response = target_tcp.recv(1024).decode('utf-8', errors='ignore').splitlines()[0]
        print(f"Ports {port} Is: {response}")
    except Exception as e:
        print(f"[-] Failed to grab banner on port {port}")
    finally:
        target_tcp.close()
    
grab_banner("httpbin.org", 80)