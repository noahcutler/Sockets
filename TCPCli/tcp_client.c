#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
  //create socket (one side of the network communication)
  int socket_descriptor;
  socket_descriptor= socket(AF_INET, SOCK_STREAM, 0); // DOMAIN OF SOCKET (INTERNET SOCKET), TYPE OF SOCKET (TCP), PROTOCOL

  //something to connect it to
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3581);//port number for connection 
  server_address.sin_addr.s_addr = INADDR_ANY; // will be replaced with TCP server
  int connection_status;
  connection_status = connect(socket_descriptor, (struct sockaddr_in*) &server_address, sizeof(server_address) );
    if (connection_status == -1){
      printf("Sincerest apologies! something went wrong while attempting to establish a connection!");}

  //recieve data
  char server_response[256];
  recv(socket_descriptor, &server_response, sizeof(server_response), 0); // flags set to 0
  //print the server's response
  printf("The server sent some data: %s\n", server_response);
  close(socket_descriptor);
  return 0;
  
}
