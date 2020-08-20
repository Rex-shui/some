#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_READ_LINE 1024

int main(void) {
    char buff[MAX_READ_LINE];
    int recv_len = -1;
    int conn_fd = -1;
    int ret = -1;
    int server_ip_port = 9999;

    struct sockaddr_in t_sockaddr;
    memset(&t_sockaddr, 0, sizeof(t_sockaddr));
    t_sockaddr.sin_family = AF_INET;
	//INADDR_ANY 0.0.0.0 listen all ports of machine
	//machine may have some network cards
    t_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    t_sockaddr.sin_port = htons(server_ip_port);
	
	//int socket(int domin, int type, int protocol);
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
		//when the call fails, error code to 'errno', 'strerror' trans err code to string, -_-+ 
        fprintf(stderr, "socket error %s errno: %d\n", strerror(errno), errno);
    }

    ret = bind(listen_fd,(struct sockaddr *) &t_sockaddr,sizeof(t_sockaddr));
    if (ret < 0) {
        fprintf(stderr, "bind socket error %s errno: %d\n", strerror(errno), errno);
    }
	
	//1024... 'backlog'
    ret = listen(listen_fd, 1024);
    if (ret < 0) {
        fprintf(stderr, "listen error %s errno: %d\n", strerror(errno), errno);
    }

    for(;;) {
		//int accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
        conn_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);
        if(conn_fd < 0) {
            fprintf(stderr, "accpet socket error: %s errno :%d\n", strerror(errno), errno);
            continue;
        }

        recv_len = recv(conn_fd, buff, MAX_READ_LINE, 0);
        if (recv_len < 0) {
            fprintf(stderr, "recv error %s errno: %d\n", strerror(errno), errno);
            continue;
        }

        buff[recv_len] = '\0';
        fprintf(stdout, "recv message from client: %s\n", buff);
        close(conn_fd);
        conn_fd = -1;
    }

    close(listen_fd);
    listen_fd = -1;

    return 0;
}