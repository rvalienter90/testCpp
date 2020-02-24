/* UDP client in the internet domain */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct bsm
{
	u_int8_t id;
	u_int8_t tx_time;
}bsm_t;

void error(const char *);
int main(int argc, char *argv[])
{
   printf("Start client\n");
   int sock, n;
   unsigned int length;
   struct sockaddr_in server, from;
   struct hostent *hp;
   char buffer[256];
   bsm_t* mybsm[5];
       int i;
       for(i = 0; i < 5; i++){
         mybsm[i] = (struct bsm*) malloc(1 * sizeof(struct bsm));
       }

       for(i = 0; i < 5; i++){
         mybsm[i]->id = i+1;
         mybsm[i]->tx_time = (i+1)*5;
       }
   
   if (argc != 3) { printf("Usage: server port\n");
                    exit(1);
   }
   for(i = 0; i < 5; i++){
   sock= socket(AF_INET, SOCK_DGRAM, 0);
   if (sock < 0) error("socket");

   server.sin_family = AF_INET;
   hp = gethostbyname(argv[1]);
   if (hp==0) error("Unknown host");

   bcopy((char *)hp->h_addr, 
        (char *)&server.sin_addr,
         hp->h_length);
   server.sin_port = htons(atoi(argv[2]));
   length=sizeof(struct sockaddr_in);
   /*printf("Please enter the message: ");
   bzero(buffer,256);
   fgets(buffer,255,stdin);
   n=sendto(sock,buffer,
            strlen(buffer),0,(const struct sockaddr *)&server,length);*/

   printf("Sending the Packet from client to server\n");
   printf("Test\n");
   n=sendto(sock,mybsm[i],
		   sizeof(mybsm[i]),0,(const struct sockaddr *)&server,length);
   if (n < 0) error("Sendto");
   n = recvfrom(sock,buffer,256,0,(struct sockaddr *)&from, &length);
   if (n < 0) error("recvfrom");
   write(1,"Got an ack: ",12);
   write(1,buffer,n);
   close(sock);
   }
   return 0;
}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}
