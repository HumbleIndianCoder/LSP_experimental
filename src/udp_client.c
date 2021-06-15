#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(int argc, char *argv[]) { 

	int csd, port;
	struct sockaddr_in server;
	char buff[100];

	strcpy(buff, " Hello, this is a UDP Packet ");

	// creating the UDP socket
	csd = socket(AF_INET, SOCK_DGRAM, 0);

	// Filling the sockaddr_in details
	
	port = atoi(argv[2]);

	server.sin_family 	= AF_INET;
	server.sin_addr.s_addr  = inet_addr(argv[1]);
	server.sin_port 	= htons(port);

	int len, n;
	len = sizeof(server);

	// Send the message to the server
        sendto(csd, buff, sizeof(buff), 0, (struct sockaddr*)&server, len);

	// Recieve the message from server
	n = recvfrom(csd, buff, sizeof(buff), 0, (struct sockaddr*)&server, &len);
	buff[n] = '\0';
	printf(" From Server: %s\n", buff);


	close(csd);


	return 0;
}
