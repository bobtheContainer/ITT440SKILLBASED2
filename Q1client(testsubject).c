#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h> //inet_addr
//Q1 Client
int main(int argc , char *argv[])
{
int socket_desc;
int r_num;
struct sockaddr_in server;
 char *message;
//Create socket
socket_desc = socket(AF_INET , SOCK_STREAM , 0);
if (socket_desc == -1)
{
printf("Could not create socket");
}
server.sin_addr.s_addr = inet_addr("192.168.188.128"); //Please enter the ip address of your Server VM
server.sin_family = AF_INET;
server.sin_port = htons( 8080 );
//Connect to remote server
if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
{
puts("connect error");
return 1;
}
puts("Connected \n");
 //Receive a reply from the server
if( recv(socket_desc,&r_num,sizeof(r_num), 0) < 0)
{
puts("recv failed");
return 0;
}
printf("Random number from server: %d\n",r_num);
close(socket_desc);
return 0;
}
