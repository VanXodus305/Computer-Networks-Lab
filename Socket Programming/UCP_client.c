#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8081
#define BUFFER_SIZE 1024

int main()
{
  int client_fd;
  struct sockaddr_in server_addr;
  socklen_t server_len = sizeof(server_addr);
  char *message = "Hello from UDP client!";
  char buffer[BUFFER_SIZE] = {0};

  if ((client_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0)
  {
    perror("Invalid address/ Address not supported");
    close(client_fd);
    exit(EXIT_FAILURE);
  }

  printf("Connecting to UDP server...\n");

  int bytes_sent = sendto(client_fd, message, strlen(message), 0,
                          (struct sockaddr *)&server_addr, server_len);

  if (bytes_sent < 0)
  {
    perror("Send failed");
    close(client_fd);
    exit(EXIT_FAILURE);
  }

  printf("Message sent to server: %s\n", message);

  int bytes_received = recvfrom(client_fd, buffer, BUFFER_SIZE, 0,
                                (struct sockaddr *)&server_addr, &server_len);

  if (bytes_received < 0)
  {
    perror("Receive failed");
    close(client_fd);
    exit(EXIT_FAILURE);
  }

  buffer[bytes_received] = '\0'; 
  printf("Response from server: %s\n", buffer);

  close(client_fd);

  return 0;
}
