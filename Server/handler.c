#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
* This will handle connection for each client
* */
void *connection_handler(void *socket_desc)
{
//Get the socket descriptor
int sock = *(int*)socket_desc;
int read_size;
char *message , client_message[2000];
//Send some messages to the client
message = "Greetings! I am your connection handler\n";
write(sock , message , strlen(message));
message = "Now type something and i shall repeat what you type \n";
write(sock , message , strlen(message));
//Receive a message from client
while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
{
//Send the message back to client
write(sock , client_message , strlen(client_message));
}
if(read_size == 0)
{
puts("Client disconnected");
fflush(stdout);
}
else if(read_size == -1)
{
perror("recv failed");
}
//Free the socket pointer
free(socket_desc);
return 0;
}
