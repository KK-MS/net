/*
   Create a TCP socket
   */
#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
int main(int argc , char *argv[])
{
  WSADATA wsa;
  SOCKET s;
  struct sockaddr_in server;
  char *message , server_reply[2000];
  int recv_size;
  printf("\nInitialising Winsock...");
  if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
  {
    printf("Failed. Error Code : %d",WSAGetLastError());
    return 1;
  }

  printf("Initialised.\n");
  fflush(stdout);

  //Create a socket
  if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
  {
    printf("Could not create socket : %d" , WSAGetLastError());
  }
  printf("Socket created.\n");
  fflush(stdout);


  //server.sin_addr.s_addr = inet_addr("74.125.235.20");
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  //server.sin_port = htons( 80 );
  server.sin_port = htons( 8888 );
  //Connect to remote server
  if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
  {
    puts("connect error");
    fflush(stdout);
    return 1;
  }

  puts("Connected");
  fflush(stdout);

  //Send some data
  message = "GET / HTTP/1.1\r\n\r\n";
  if( send(s , message , strlen(message) , 0) < 0)
  {
    puts("Send failed");
    fflush(stdout);
    return 1;
  }
  puts("Data Send\n");
  fflush(stdout);

  //Receive a reply from the server
  if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
  {
    puts("recv failed");
    fflush(stdout);
  }

  puts("Reply received\n");
  fflush(stdout);
  //Add a NULL terminating character to make it a proper string before printing
  server_reply[recv_size] = '\0';
  puts(server_reply);
  return 0;
}
