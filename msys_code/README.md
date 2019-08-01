*

Compile command
----------------
gcc tcp_server.c  -o server_tcp -lwsock32

gcc tcp_client.c  -o client_tcp -lwsock32


Server logs:
------------

k.mayannavar@LL-NB-09 MINGW64 /c/prj/gt/net
$ ./server_tcp.exe

Initialising Winsock...and b4 WSAStartup
Initialised.
Socket created.
Bind done
Waiting for incoming connections...
Connection accepted
Connection accepted
Connection accepted


client logs:
------------
k.mayannavar@LL-NB-09 MINGW64 /c/prj/gt/net
$ ./client_tcp.exe

Initialising Winsock...Initialised.
Socket created.
Connected
Data Send

Reply received

Hello Client , I have received your connection. But I have to go now, from A-Driver. bye. Count::2

k.mayannavar@LL-NB-09 MINGW64 /c/prj/gt/net
$ ./client_tcp.exe

Initialising Winsock...Initialised.
Socket created.
Connected
Data Send

Reply received

Hello Client , I have received your connection. But I have to go now, from A-Driver. bye. Count::3

k.mayannavar@LL-NB-09 MINGW64 /c/prj/gt/net


