#include <stdio.h>

#include <stdlib.h>

#include <signal.h>

#include <unistd.h>

#include <string.h>

#include <sys/socket.h>

#include <netinet/in.h>

 

#define PORT 9000

 

static int server_fd = -1;

 

static void handle_signal(int sig)

{

    (void)sig;

    if (server_fd >= 0) {

        close(server_fd);

    }

    _exit(0);

}

 

int main(void)

{

    struct sockaddr_in addr;

 

    signal(SIGINT, handle_signal);

    signal(SIGTERM, handle_signal);

 

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {

        perror("socket");

        return 1;

    }

 

    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;

    addr.sin_addr.s_addr = INADDR_ANY;

    addr.sin_port = htons(PORT);

 

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {

        perror("bind");

        close(server_fd);

        return 1;

    }

 

    if (listen(server_fd, 5) < 0) {

        perror("listen");

        close(server_fd);

        return 1;

    }

 

    while (1) {

        pause();

    }

 

    return 0;

}
