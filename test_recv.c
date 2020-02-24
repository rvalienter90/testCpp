//#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//using namespace std;

#define BUFSIZE 1024



//gcc -o test_send test_send.cpp
struct custom_bsm {
    int 	id;
    int     type;
    double  tx_time;
    double  lat;
    double  lon;
    double  alt;
    double  speed;

}__attribute__((__packed__));

typedef struct custom_bsm  CUSTOM_bsm ;
CUSTOM_bsm* pkt_to_recv;

//char ip[15]="127.0.0.1";
//char ip[25]="192.168.1.77";

void error(char *msg) {
    perror(msg);
    exit(0);
}



// C
void receive_udp_C(){
    int sockfd; /* socket */
    int portno; /* port to listen on */
    int clientlen; /* byte size of client's address */
    struct sockaddr_in serveraddr; /* server's addr */
    struct sockaddr_in clientaddr; /* client addr */
    struct hostent *hostp; /* client host info */
    char buf[BUFSIZE]; /* message buf */
    char *hostaddrp; /* dotted decimal host addr string */
    int optval; /* flag value for setsockopt */
    int n; /* message byte size */

    /*
     * check command line arguments
     *
     *   if (argc != 2) {
      fprintf(stderr, "usage: %s <port>\n", argv[0]);
      exit(1);
      portno = atoi(argv[1]);
    }
     */

    portno=12002;

    /*
     * socket: create the parent socket
     */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* setsockopt: Handy debugging trick that lets
     * us rerun the server immediately after we kill it;
     * otherwise we have to wait about 20 secs.
     * Eliminates "ERROR on binding: Address already in use" error.
     */
    optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
               (const void *)&optval , sizeof(int));

    /*
     * build the server's Internet address
     */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short)portno);

    /*
     * bind: associate the parent socket with a port
     */
    if (bind(sockfd, (struct sockaddr *) &serveraddr,
             sizeof(serveraddr)) < 0)
        error("ERROR on binding");

    /*
     * main loop: wait for a datagram, then echo it
     */
    clientlen = sizeof(clientaddr);
    while (1) {

        /*
         * recvfrom: receive a UDP datagram from a client
         */
        bzero(buf, BUFSIZE);
        n = recvfrom(sockfd, buf, BUFSIZE, 0,
                     (struct sockaddr *) &clientaddr, &clientlen);
        if (n < 0)
            error("ERROR in recvfrom");

        /*
         * gethostbyaddr: determine who sent the datagram
         */
        hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
                              sizeof(clientaddr.sin_addr.s_addr), AF_INET);
        if (hostp == NULL)
            error("ERROR on gethostbyaddr");
        hostaddrp = inet_ntoa(clientaddr.sin_addr);
        if (hostaddrp == NULL)
            error("ERROR on inet_ntoa\n");
        printf("server received datagram from %s (%s)\n",
               hostp->h_name, hostaddrp);
        printf("server received %d/%d bytes: %s\n", (int)strlen(buf), n, buf);

        /*
         * sendto: echo the input back to the client
         */
        n = sendto(sockfd, buf, strlen(buf), 0,
                   (struct sockaddr *) &clientaddr, clientlen);
        if (n < 0)
            error("ERROR in sendto");
    }
}
void receive_udp_long(int portno){
    int sockfd; /* socket */
    //int portno; /* port to listen on */
    int clientlen; /* byte size of client's address */
    struct sockaddr_in serveraddr; /* server's addr */
    struct sockaddr_in clientaddr; /* client addr */
    struct hostent *hostp; /* client host info */
    char buf[BUFSIZE]; /* message buf */
    char *hostaddrp; /* dotted decimal host addr string */
    int optval; /* flag value for setsockopt */
    int n; /* message byte size */


    /*
     * socket: create the parent socket
     */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* setsockopt: Handy debugging trick that lets
     * us rerun the server immediately after we kill it;
     * otherwise we have to wait about 20 secs.
     * Eliminates "ERROR on binding: Address already in use" error.
     */
    optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
               (const void *)&optval , sizeof(int));

    /*
     * build the server's Internet address
     */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short)portno);

    /*
     * bind: associate the parent socket with a port
     */
    if (bind(sockfd, (struct sockaddr *) &serveraddr,
             sizeof(serveraddr)) < 0)
        error("ERROR on binding");

    /*
     * main loop: wait for a datagram, then echo it
     */
    clientlen = sizeof(clientaddr);
    while (1) {

        /*
         * recvfrom: receive a UDP datagram from a client
         */
        bzero(buf, BUFSIZE);
        n = recvfrom(sockfd, buf, BUFSIZE, 0,
                     (struct sockaddr *) &clientaddr, &clientlen);
        if (n < 0)
            error("ERROR in recvfrom");

        /*
         * gethostbyaddr: determine who sent the datagram
         */
        hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
                              sizeof(clientaddr.sin_addr.s_addr), AF_INET);
        if (hostp == NULL)
            error("ERROR on gethostbyaddr");
        hostaddrp = inet_ntoa(clientaddr.sin_addr);
        if (hostaddrp == NULL)
            error("ERROR on inet_ntoa\n");
        printf("server received datagram from %s (%s)\n",
               hostp->h_name, hostaddrp);
        printf("server received %d/%d bytes: %s\n", (int)strlen(buf), n, buf);

        /*
         * sendto: echo the input back to the client
         */
        n = sendto(sockfd, buf, strlen(buf), 0,
                   (struct sockaddr *) &clientaddr, clientlen);
        if (n < 0)
            error("ERROR in sendto");
    }
}
int receive_udp(int portno){
    int sock; /* socket */
    //int portno; /* port to listen on */
    int addlen; /* byte size of client's address */
    char buf[BUFSIZE]; /* message buf */
    int optval; /* flag value for setsockopt */
    int n; /* message byte size */


    // open UDP socket ,create the parent socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("ERROR opening socket\n"); return 1;}

    /* setsockopt: Handy debugging trick that lets
     * us rerun the server immediately after we kill it;
     * otherwise we have to wait about 20 secs.
     * Eliminates "ERROR on binding: Address already in use" error.
     */
    optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,(const void *)&optval , sizeof(int));

    //build the server's Internet address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr =  htonl(INADDR_ANY);;
    server_addr.sin_port = htons((unsigned short)portno);

    //bind: associate the parent socket with a port
    if (bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        printf("ERROR on binding\n");
        //error("ERROR on binding");

    addlen = sizeof(server_addr);
    while (1) {

        //recvfrom: receive a UDP datagram from a client
        bzero(buf, BUFSIZE);
        n = recvfrom(sock, buf, BUFSIZE, 0,
                     (struct sockaddr *) &server_addr, &addlen);
        if (n < 0)
            printf("ERROR in recvfrom\n");
            //error("ERROR in recvfrom");
        printf("server received %d/%d bytes: %s\n", (int)strlen(buf), n, buf);

        /*
         * sendto: echo the input back to the client
         */
    }
}
int receive_udp_struct(int portno){
    int sock; /* socket */
    //int portno; /* port to listen on */
    int addlen; /* byte size of client's address */
    int optval; /* flag value for setsockopt */
    int n; /* message byte size */


    // open UDP socket ,create the parent socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("ERROR opening socket\n"); return 1;}

    /* setsockopt: Handy debugging trick that lets
     * us rerun the server immediately after we kill it;
     * otherwise we have to wait about 20 secs.
     * Eliminates "ERROR on binding: Address already in use" error.
     */
    optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR,(const void *)&optval , sizeof(int));

    //build the server's Internet address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr =  htonl(INADDR_ANY);;
    server_addr.sin_port = htons((unsigned short)portno);

    //bind: associate the parent socket with a port
    if (bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        printf("ERROR on binding\n");
    //error("ERROR on binding");

    addlen = sizeof(server_addr);
    pkt_to_recv = (struct custom_bsm *) calloc(1,1 * sizeof(CUSTOM_bsm));
    while (1) {

        //recvfrom: receive a UDP datagram from a client
        n = recvfrom(sock, pkt_to_recv, sizeof(CUSTOM_bsm), 0,
                     (struct sockaddr *) &server_addr, &addlen);

        //sscanf(message, "%*s %d %*s %f %*s %f", &id, &X, &Y);
        if (n < 0)
            printf("ERROR in recvfrom\n");
        //error("ERROR in recvfrom");
       // printf("server received %d/%d bytes\n", (int)strlen(pkt_to_recv), n);
        printf("pkt_to_recv->id %d, pkt_to_recv->type %d \n",pkt_to_recv->id,pkt_to_recv->type);
        printf("pkt_to_recv->tx_time %f, pkt_to_recv->lat %f \n",pkt_to_recv->tx_time,pkt_to_recv->lat);
        /*
         * sendto: echo the input back to the client
         */
    }
}

int main(){

    receive_udp_struct(12002);
    //receive_udp_C();
}

