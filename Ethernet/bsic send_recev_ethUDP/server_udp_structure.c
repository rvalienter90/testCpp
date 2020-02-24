/* Creates a datagram server.  The port 
   number is passed as an argument.  This
   server runs forever */

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>

typedef struct bsm
{
	u_int8_t id;
	u_int8_t tx_time;
}bsm_t;



void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
   printf("Start server\n");
   int sock, length, n;
   socklen_t fromlen;
   struct sockaddr_in server;
   struct sockaddr_in from;
   char buf[1024];

   bsm_t* mybsm;
   mybsm = (struct bsm*) malloc(1 * sizeof(struct bsm));
   mybsm->id = 0;
   mybsm->tx_time = 0;

   printf("id = %d, tx_time = %d\n", mybsm->id, mybsm->tx_time);
   if (argc < 2) {
      fprintf(stderr, "ERROR, no port provided\n");
      exit(0);
   }
   
   sock=socket(AF_INET, SOCK_DGRAM, 0);
   if (sock < 0) error("Opening socket");
   length = sizeof(server);
   bzero(&server,length);
   server.sin_family=AF_INET;
   server.sin_addr.s_addr=INADDR_ANY;
   server.sin_port=htons(atoi(argv[1]));
   if (bind(sock,(struct sockaddr *)&server,length)<0) 
       error("binding");
   fromlen = sizeof(struct sockaddr_in);
   while (1) {
       //n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);
	   n = recvfrom(sock,mybsm,sizeof(mybsm),0,(struct sockaddr *)&from,&fromlen);

	   if (n < 0) error("recvfrom");
       write(1,"Received a datagram: ",21);
       write(1,buf,n);
	   printf("Here is the message: id = %d, tx_time = %ds\n",mybsm->id, mybsm->tx_time);

       n = sendto(sock,"Got your message\n",17,
                  0,(struct sockaddr *)&from,fromlen);
       if (n  < 0) error("sendto");
   }
   return 0;
 }

