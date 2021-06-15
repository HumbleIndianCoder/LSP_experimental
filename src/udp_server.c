#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(int argc, char *argv[]) { 

	int sockfd, port;
	struct sockaddr_in server, client;

	// creating the UDP socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	// Filling the sockaddr_in details
	
	port = atoi(argv[1]);

	server.sin_family 	= AF_INET;
	server.sin_addr.s_addr  = inet_addr("127.0.0.1");//INADDR_ANY;
	server.sin_port 	= htons(port);

	// bind the ip addr and port to the socket
	bind(sockfd, (struct sockaddr*)&server, sizeof(server));

	// Need to recieve the message from the client
	char buff[100];
	int n;
	int len = sizeof(client);

	n = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&client, &len);
	buff[n] = '\0';
	printf(" Fron Client: %s\n", buff);

	// Send the same message back to the client
	sendto(sockfd, buff, n, 0, (struct sockaddr*)&client, len);

	close(sockfd);


	return 0;
}
