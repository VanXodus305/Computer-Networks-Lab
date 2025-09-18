#include <stdio.h>     // printf, perror
#include <stdlib.h>    // exit, EXIT_FAILURE
#include <string.h>    // memset, strlen
#include <unistd.h>    // close, read, write
#include <arpa/inet.h> // sockaddr_in, inet_addr, htons

#define PORT 8080

int main()
{
  int sock = 0;
  struct sockaddr_in serv_addr;
  char *message = "Hello from client!";
  char buffer[1024] = {0};

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("Socket creation error");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
  {
    perror("Invalid address/ Address not supported");
    return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("Connection Failed");
    return -1;
  }

  printf("Connected to server!\n");

  send(sock, message, strlen(message), 0);
  printf("Message sent to server: %s\n", message);

  read(sock, buffer, 1024);
  printf("Response from server: %s\n", buffer);

  close(sock);

  return 0;
}