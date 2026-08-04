#include <stdio.h> //library file to include scanf and printf
#include <stdlib.h>//library file to include fgets and fputs  
#include <string.h>// library file to include string related functions
#include <unistd.h>// unix standard library
#include <arpa/inet.h> // header file to include socket and ipv4 related functions 

int main()
{
    int sockfd, newsockfd;
    // creates 2 socket descriptors 
    // sockfd - stores socket created by socket()
    // newsockfd -used to store socket created by client (accept())
    


    struct sockaddr_in server, client;
    // structure that stores address of client and server 
    // what all are there in struct sockaddr_in ??
    // the structure has sin_family denoting the family of address of socket ipv4    
    socklen_t addr_size;
    //variable that stores that size of address 

    char buffer[1024];
    // to store msgs sent and read by client nd server 

    // Step 1: Create Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Step 2: Fill Server Address and all other related details of server
    server.sin_family = AF_INET;
    server.sin_port = htons(8080); 
    // converts 16 bit host byte order to network byte work 
    server.sin_addr.s_addr = INADDR_ANY;
    // accept any local ip address
    
    // Step 3: Bind
    bind(sockfd,(struct sockaddr *)&server,sizeof(server));
    //bind() -binds the server socket with the client socket 

    // Step 4: Listen
    listen(sockfd, 5);
    //listen()- makes the server to listen or wait for the client requests 
    //5 refers to backlogs which refers to number of pending requests that the server can handle 
    

    printf("Waiting for client...\n");

    // Step 5: Accept
    addr_size = sizeof(client);

    newsockfd = accept(sockfd,
                       (struct sockaddr *)&client,
                       &addr_size);

    printf("Client Connected!\n");
    
    //accept() - accepts a request frm a client nd connects the server with the client 
    //accept() - always has data related to client 
    // accept () - creates a new socket identified by newscokfd for communicating with that client.
    

    // Step 6: Receive data send by the client  
    recv(newsockfd,
         buffer,
         sizeof(buffer),
         0);

    printf("Client Says: %s\n", buffer);

    // Step 7: Send Reply to the client 
    strcpy(buffer, "Hello Client");

    send(newsockfd,
         buffer,
         strlen(buffer),
         0);

    // Step 8: Close the socket created  by server
    close(newsockfd);
    close(sockfd);

    return 0;
}
