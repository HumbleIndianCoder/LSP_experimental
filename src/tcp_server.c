#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERVER_ADDR "127.0.0.1"

void transact_with_client(int cl_sock) {

	char buf[100];
	int n;

	while((n=recv(cl_sock, buf, sizeof(buf), 0))>0) {

	       send(cl_sock, buf, n, 0);
       	       write(1, buf, n);	       

	}

}

int main(int argc, char *argv[]) {

	int sockfd, port, size, csd;
	struct sockaddr_in server, client;

	int servPort;
	struct sockaddr_in saddr; char servIP[16];

	// creating a TCP socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// port given by user : ./server 5000
	port = atoi(argv[1]);

	// Filling the IP address & port to sockaddr_in
	server.sin_family      = AF_INET;
	server.sin_port        = htons(port);
	server.sin_addr.s_addr = inet_addr(SERVER_ADDR); //INADDR_ANY;

	// bind the socket
	bind(sockfd, (struct sockaddr*)&server, sizeof(server));

	// listen , backlog of 5 req
	listen(sockfd, 5);

	// get socket details
	bzero(&saddr, sizeof(saddr));
	size = sizeof(saddr);

	getsockname(sockfd, (struct sockaddr*)&saddr, &size);
	inet_ntop(AF_INET, &saddr.sin_addr.s_addr, servIP, sizeof(servIP));
	printf("IP assigned by this server is %s\n", servIP);
	servPort = ntohs(saddr.sin_port);
	printf("Port = %d\n", servPort);

	while(1) {

		size = sizeof(client);
		csd = accept(sockfd, (struct sockaddr*)&client, &size);
		transact_with_client(csd);
		close(csd);
	}

	close(sockfd);


	return 0;
}
