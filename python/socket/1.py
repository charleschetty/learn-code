from audioop import add
# import imp
from secrets import choice
import socket,argparse
import datetime
from string import printable

max_bytes=65535


def service(port):
    sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    sock.bind(('127.0.0.1',port))
    print('listen at {}'.format(sock.getsockname()))
    while True:
        data,address=sock.recvfrom(max_bytes)
        text=data.decode("ascii")
        print("the client at {} says {}".format(address,text))
        text="your data was {} bytes long".format(len(data))
        data=text.encode('ascii')
        sock.sendto(data,address)


def client(port):
    sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    text ="the time is {}".format(datetime.datetime.now())
    data=text.encode('ascii')

    # sock.sendto(data,('127.0.0.1',port))
    sock.connect(('127.0.0.1',port))
    sock.send(data)

    print("the os assigned me at {}".format(sock.getsockname))

    # data,address=sock.recvfrom(max_bytes)
    data=sock.recv(max_bytes)

    text=data.decode('ascii')
    
    # print("the server {} replied {}".format(address,text))
    print("the server replied {}".format(text))

if __name__=='__main__':
    choice={'client':client,'server':service}
    parser1=argparse.ArgumentParser(description="send and receieve udp locally")
    parser1.add_argument('role',choices=choice,help='wwww')
    parser1.add_argument('-p',metavar="PORT",type=int,default=1060,help="udp port")
    args=parser1.parse_args()
    function=choice[args.role]
    function(args.p)

