#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int fd_socket;
	struct sockaddr_in s_addr;
	char buf[256];
	s_addr.sin_family=AF_INET;
        s_addr.sin_port=htons(29284);
        s_addr.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
	fd_socket=socket(AF_INET,SOCK_STREAM,0);
	if(connect(fd_socket,(struct sockaddr*)&s_addr, sizeof(s_addr))==-1){
		perror("connect");
		exit(-1);
	}
	recv(fd_socket,buf,256,0);
	printf("%s",buf);
}

