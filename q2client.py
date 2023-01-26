import socket
#Q2 CLIENT
s = socket.socket()

port = 2222
host ='192.168.188.128'

try:
	s.connect((host,port))
	message = input("Farenheit to be convert by server : ")
	s.send(message.encode())
	data=s.recv(1024)
	print(data.decode())
finally:
	s.close()
