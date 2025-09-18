#include <stdio.h>      // printf, perror
#include <stdlib.h>     // exit, EXIT_FAILURE
#include <string.h>     // memset, strlen
#include <unistd.h>     // close, read, write
#include <arpa/inet.h>  // sockaddr_in, inet_addr, htons
#include <sys/socket.h> // socket, bind, recvfrom, sendto

#define PORT 8081
#define BUFFER_SIZE 1024

int main()
{
  int server_fd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buffer[BUFFER_SIZE] = {0};
  char *response = "Hello from UDP server!";

  if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
  {
    perror("Bind failed");
    close(server_fd);
    exit(EXIT_FAILURE);
  }

  printf("UDP Server listening on port %d...\n", PORT);

  int bytes_received = recvfrom(server_fd, buffer, BUFFER_SIZE, 0,
                                (struct sockaddr *)&client_addr, &client_len);

  if (bytes_received < 0)
  {
    perror("Receive failed");
    close(server_fd);
    exit(EXIT_FAILURE);
  }

  buffer[bytes_received] = '\0';
  printf("Message from client: %s\n", buffer);

  int bytes_sent = sendto(server_fd, response, strlen(response), 0,
                          (struct sockaddr *)&client_addr, client_len);

  if (bytes_sent < 0)
  {
    perror("Send failed");
    close(server_fd);
    exit(EXIT_FAILURE);
  }

  printf("Response sent to client\n");

  close(server_fd);

  return 0;
}