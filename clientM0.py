import socket
import select
import sys
import threading
port = 6075
HEADER = 64
FORMAT = 'utf-8'
#def send (msg):
 #message = msg.encode(FORMAT)
 #msg_length = len(message)
# send_length = str(msg_length).encode(FORMAT)
 #send_length += b' ' * (HEADER - len(send_length)) 
 #client_socket.send(send_length)
# client_socket.send(message)
 #print(client_socket.recv(2048).decode(FORMAT))

#while True:
 #   msg = input()
 #   s.send(msg.encode())
  #  if msg=='CLOSE SOCKET':
   #     break
   # print(s.recv(1024).decode())
#s.close()

def main():

    client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    print("Socket successfully created")

    
    client_socket.connect(("127.0.0.1", port))

    connected= True
    while connected :
        msg = input("enter your message: ")
        client_socket.send(msg.encode(FORMAT))

        if msg=="CLOSE SOCKET":
            connected= False
        else:
           
            print(client_socket.recv(1024).decode(FORMAT))
    client_socket.close()





if __name__=="__main__":
    main()