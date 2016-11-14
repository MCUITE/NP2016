#include<stdio.h> //printf
#include<string.h> //strcpy
#include<sys/socket.h>
#include<netdb.h> //hostent
#include<arpa/inet.h>
int main(int argc , char *argv[])
{
char *hostname = "www.google.com";
char ip[100];
struct hostent *he;
struct in_addr **addr_list;
int i;


if (argc!=2)
{
	printf("Usage: %s <hostname>\n" , argv[0]);
	return 1;
}


if ( (he = gethostbyname( argv[1] ) ) == NULL)
{
	//gethostbyname failed
	herror("gethostbyname");
	return 1;
}

//Cast the h_addr_list to in_addr , since h_addr_list also has the ip address in long format only
addr_list = (struct in_addr **) he->h_addr_list;


for(i = 0; addr_list[i] != NULL; i++)
{
	//Return the first one;
	strcpy(ip , inet_ntoa(*addr_list[i]) );
	printf("%s resolved to : %s\n" , argv[1] , ip);
}

return 0;
}
