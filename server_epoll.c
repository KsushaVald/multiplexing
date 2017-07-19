#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>

int main(){
        int fd_socket_tcp, fd_socket_udp, fd_client; int test;
        struct sockaddr_in my_addr_tcp, my_addr_udp, client_udp, client_tcp;
        socklen_t len_t=sizeof(struct sockaddr);
        socklen_t len_u=sizeof(struct sockaddr);
        int fd_epoll; struct epoll_event  event;
	char time[256]; char buf[256];
        struct  tm *m_time; long int s_time;

        my_addr_tcp.sin_family=AF_INET;
        my_addr_tcp.sin_port=htons(29284);
        my_addr_tcp.sin_addr.s_addr=htonl(INADDR_ANY);

        my_addr_udp.sin_family=AF_INET;
        my_addr_udp.sin_port=htons(35284);
        my_addr_udp.sin_addr.s_addr=htonl(INADDR_ANY);

        fd_socket_tcp=socket(AF_INET, SOCK_STREAM,0);
        fd_socket_udp=socket(AF_INET,SOCK_DGRAM,0);

	if(bind(fd_socket_tcp,(struct sockaddr*)&my_addr_tcp,sizeof(my_addr_tcp$
                perror("bind");
        }
        if(bind(fd_socket_udp,(struct sockaddr*)&my_addr_udp,sizeof(my_addr_udp$
                perror("bind");
        }
        listen(fd_socket_tcp,1);
	fd_epoll=epoll_create(2);
	event.events=EPOLINT;
	event.data
	epoll_ctl(fd_epoll,EPOLL_CTL_ADD,fd_socket_tcp,&events);
	epoll_ctl(fd_epoll,EPOLL_CTL_ADD,fd_socket_udp,&events);
 	while(1){
                test=epoll_wait(fd_epoll,&events,,2000);
                if(test==-1){
                        perror("epol_wait");
                        exit(-1);
                }
                else{
                        if(test!=0){
                                s_time=times(NULL);
                                m_time=localtime(&s_time);
                                strcpy(time,asctime(m_time));
                                //if(p[0].revents&POLLIN){
                                        fd_client=accept(fd_socket_tcp,(struct $
                                        send(fd_client,time,sizeof(time),0);
                                }
                                //if(p[1].revents&POLLIN){
                                        recvfrom(fd_socket_udp,&buf,sizeof(time$
                                        sendto(fd_socket_udp,time,sizeof(time),$
                                }
                        }
                }
        }
}

