#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


void transact_with_server(int csd) {

	char buf[100];
	int n;

	while(1) {

		bzero(buf, sizeof(buf));
		fgets(buf, sizeof(buf)-1, stdin);

		// send to server
		send(csd, buf, strlen(buf), 0);
		
		// from server
		n=recv(csd, buf, sizeof(buf), 0);
		
		// print it
		write(STDOUT_FILENO, buf, n);

	}



}



int main(int argc, char *argv[]) {

	int clsd, port;
	struct sockaddr_in server, client;

	// creating a TCP socket
	clsd = socket(AF_INET, SOCK_STREAM, 0);

	// Init the server structure with zeroes
	memset(&server, 0, sizeof(struct sockaddr_in));

	// port given by user : ./client 5000
	port = atoi(argv[2]);

	// Filling the IP address & port of the server to sockaddr_in
	server.sin_family      = AF_INET;
	server.sin_port        = htons(port);
	server.sin_addr.s_addr = inet_addr(argv[1]);

	// connect to the server using client sock fd
	connect(clsd, (struct sockaddr*)&server, sizeof(server));

	// comm with server
	transact_with_server(clsd);

	close(clsd);


	return 0;
}
