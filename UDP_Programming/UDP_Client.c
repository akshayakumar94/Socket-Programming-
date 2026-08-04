#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server;

    char buffer[1024];

    socklen_t addr_size;

    // Step 1: Create Socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Step 2: Configure Server Address
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    addr_size = sizeof(server);

    // Step 3: Send Message
    strcpy(buffer, "Hello Server");

    sendto(sockfd,
           buffer,
           strlen(buffer),
           0,
           (struct sockaddr *)&server,
           addr_size);

    // Step 4: Receive Reply
    recvfrom(sockfd,
             buffer,
             sizeof(buffer),
             0,
             NULL,
             NULL);

    printf("Server Says: %s\n", buffer);

    // Step 5: Close Socket
    close(sockfd);

    return 0;
}
