import socket
import threading
import select
import sys
port = 6075
HEADER = 64
FORMAT = 'utf-8'
RECMess= list()
def handle_client(c,add):
    print(f"\n[NEW CONNECTION] {add} connected")
    connected= True
    while connected:
        msg=c.recv(1024).decode()
        
        if msg == 'CLOSE SOCKET':
            connected=False
            
            RECMess.remove(add)
            

      
        Capital_Sentence = msg.upper()
        c.send(Capital_Sentence.encode())
    c.close()

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("I hope server_socket is starting")

   


    
    server_socket.bind(('', port))
    print("the server supposed to be binding")

   
    server_socket.listen(5)
    print("the server supposed to be listening")

    
    while True:

       
        c, add = server_socket.accept()
        RECMess.append(add)
        thread=threading.Thread(target=handle_client , args=(c,add))
       
        thread.start()
        


if __name__=="__main__":
    main()