import socket
#Q3 CLIENT
# c = client
c = socket.socket()
c.connect(("192.168.188.128", 8888))

quote_reply = c.recv(4096).decode()
print(quote_reply)

c.close()
