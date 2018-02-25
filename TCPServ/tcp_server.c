#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
  char server_mssg[256] = "You have reached th server, congrats!";
  //create the socket
  int server_socket_descriptor;
  server_socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);


  //define server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3581);
  server_address.sin_addr.s_addr = INADDR_ANY;

  //bind function called similar to connect functcion in client
  bind(server_socket_descriptor, (struct sockaddr*) &server_address, sizeof(server_address));


  //listen for connections
  listen(server_socket_descriptor, 4);  // socket descriptor, backlog (number of "waiting connectionsz"), )
  int client_socket_descriptor;
  client_socket_descriptor = accept(server_socket_descriptor, NULL, NULL);// last 2 params are about identifying connection source

  // send some data
  send(client_socket_descriptor, server_mssg, sizeof(server_mssg), 0);
  close(server_socket_descriptor);
  return 0;
}
