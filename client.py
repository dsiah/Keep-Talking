sock = socket(AF_INET, SOCK_STREAM)
sock.connect(('127.0.0.1', 1055))
sock.sendall(b'message')
sock.close()