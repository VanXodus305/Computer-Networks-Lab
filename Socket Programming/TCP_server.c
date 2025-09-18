#include <stdio.h>     // printf, perror
#include <stdlib.h>    // exit, EXIT_FAILURE
#include <string.h>    // memset, strlen
#include <unistd.h>    // close, read, write
#include <arpa/inet.h> // sockaddr_in, inet_addr, htons, bind, listen, accept

#define PORT 8080

int main()
{
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *response = "Hello from server!";

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("Socket failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
  {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0)
  {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
  {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  printf("Client connected!\n");

  read(new_socket, buffer, 1024);
  printf("Message from client: %s\n", buffer);

  send(new_socket, response, strlen(response), 0);
  printf("Response sent to client\n");

  close(new_socket);
  close(server_fd);

  return 0;
}