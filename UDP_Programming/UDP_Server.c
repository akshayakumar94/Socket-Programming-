#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server, client;

    socklen_t addr_size;

    char buffer[1024];

    // Step 1: Create Socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Step 2: Configure Server Address
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    // Step 3: Bind Socket
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    printf("UDP Server is waiting for messages...\n");

    addr_size = sizeof(client);

    // Step 4: Receive Message
    recvfrom(sockfd,
             buffer,
             sizeof(buffer),
             0,
             (struct sockaddr *)&client,
             &addr_size);

    printf("Client Says: %s\n", buffer);

    // Step 5: Send Reply
    strcpy(buffer, "Hello Client");

    sendto(sockfd,
           buffer,
           strlen(buffer),
           0,
           (struct sockaddr *)&client,
           addr_size);

    // Step 6: Close Socket
    close(sockfd);

    return 0;
}
