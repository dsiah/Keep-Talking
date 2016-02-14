from socket import *

sock = socket(AF_INET6, SOCK_STREAM)

sock.bind(('', 1055))
sock.listen(SOMAXCONN)

client, addr = sock.accept()
print(addr)
client.recv(4096)
client.close()

sock.close()