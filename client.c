#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(void) {
    char *server_ip_addr = "127.0.0.1";
    int server_ip_port = 10004;
    char *send_message = "hello";

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        fprintf(stderr, "socket error %s errno: %d\n", strerror(errno), errno);
    }

    struct sockaddr_in t_sockaddr;
    memset(&t_sockaddr, 0, sizeof(struct sockaddr_in));
    t_sockaddr.sin_family = AF_INET;
    t_sockaddr.sin_port = htons(server_ip_port);
    inet_pton(AF_INET, server_ip_addr, &t_sockaddr.sin_addr);

    if((connect(socket_fd, (struct sockaddr*)&t_sockaddr, sizeof(struct sockaddr))) < 0 ) {
        fprintf(stderr, "connect error %s errno: %d\n", strerror(errno), errno);
        return 0;
    }

    if((send(socket_fd, send_message, strlen(send_message), 0)) < 0) {
        fprintf(stderr, "send message error: %s errno : %d", strerror(errno), errno);
        return 0;
    }

    close(socket_fd);
    socket_fd = -1;

    return 0;
}