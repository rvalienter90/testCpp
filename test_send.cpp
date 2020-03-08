//#include "comsim_eth.h"
//using namespace std;
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024
//****************************Ethernet TX***********************************************//

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
CUSTOM_bsm* pkt_to_send = (struct custom_bsm *) calloc(1,1 * sizeof(custom_bsm));

//char ip[15]="127.0.0.1";
//char ip[25]="192.168.1.77";

void error(char *msg) {
    perror(msg);
    exit(0);
}

int sendto_udp_longer(char *hostname, char *message){
    int sockfd, portno, n;
    int serverlen;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buf[BUFSIZE];
    portno =12002;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);
/*
    bzero(message, BUFSIZE);
    printf("Please enter msg: ");
    fgets(message, BUFSIZE, stdin);
*/

    /* send the message to the server */
    serverlen = sizeof(serveraddr);
    n = sendto(sockfd, message, strlen(message), 0, (struct sockaddr *) &serveraddr, serverlen);

    if (n < 0)
        error("ERROR in sendto");

}

int sendto_udp(char *IP_addr, char *message)
{
    // initialize socket and portnumber
    int sock;
    int portNumber = 12002;

    // open UDP socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("ERROR opening socket\n"); return 1;}

    /* build the server's Internet address */
    struct sockaddr_in sender_addr;
    memset(&sender_addr, 0, sizeof(sender_addr));
    sender_addr.sin_family = AF_INET;
    sender_addr.sin_addr.s_addr = inet_addr(IP_addr);
    sender_addr.sin_port = htons(portNumber);

    // send message to location
    if (sendto( sock, message, strlen(message), 0,(struct sockaddr *) &sender_addr, sizeof(sender_addr)) < 0)
    {
        //perror("sendto");
        printf("ERROR sendto socket\n"); return 2;
    }

    return 0;

}


int sendto_udp_struct(char *IP_addr, CUSTOM_bsm* pkt_to_send)
{
    // initialize socket and portnumber
    int sock;
    int portNumber = 12002;

    // open UDP socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("ERROR opening socket\n"); return 1;}

    /* build the server's Internet address */
    struct sockaddr_in sender_addr;
    memset(&sender_addr, 0, sizeof(sender_addr));
    sender_addr.sin_family = AF_INET;
    sender_addr.sin_addr.s_addr = inet_addr(IP_addr);
    sender_addr.sin_port = htons(portNumber);

    // send message to location
    if (sendto( sock, pkt_to_send, sizeof(CUSTOM_bsm), 0,(struct sockaddr *) &sender_addr, sizeof(sender_addr)) < 0)
    {
        //perror("sendto");
        printf("ERROR sendto socket\n"); return 2;
    }

    return 0;

}

int sendto_udp_struct_broadcast(CUSTOM_bsm* pkt_to_send)
{
    // initialize socket and portnumber
    int sock;
    int portNumber = 12002;

    // open UDP socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("ERROR opening socket\n"); return 1;}

    // Set broadcast permissions, return if fail
    int broadcastEnable = 1;
    int ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret == -1) {printf("ERROR setsockopt\n"); return 1;}

    /* build the server's Internet address */
    struct sockaddr_in sender_addr;
    memset(&sender_addr, 0, sizeof(sender_addr));
    sender_addr.sin_family = AF_INET;
    sender_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST); // for broadcast
    sender_addr.sin_port = htons(portNumber);

    // send message to location
    if (sendto( sock, pkt_to_send, sizeof(CUSTOM_bsm), 0,(struct sockaddr *) &sender_addr, sizeof(sender_addr)) < 0)
    {
        //perror("sendto");
        printf("ERROR sendto socket\n"); return 2;
    }

    return 0;

}
//broadcast
int sendto_udp_broadcast(char *mobile_IP, char *message)
{

    // initialize socket and portnumber
    int sock;
    int portNumber = 12002;

    // open UDP socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("ERROR opening socket\n"); return 1;}
    // Set broadcast permissions, return if fail
    int broadcastEnable = 1;
    int ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret == -1) {printf("ERROR setsockopt\n"); return 1;}

    /* build the server's Internet address */
    struct sockaddr_in sender_addr;
    memset(&sender_addr, 0, sizeof(sender_addr));
    sender_addr.sin_family = AF_INET;
    sender_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST); // for broadcast
    sender_addr.sin_port = htons(portNumber);

    // send message to location
    if (sendto( sock, message, strlen(message), 0,(struct sockaddr *) &sender_addr, sizeof(sender_addr)) < 0)
    {
        //perror("sendto");
        printf("ERROR sendto socket\n"); return 2;
    }

    close(sock);

    return 0;

}



int main() {
    std::cout << "Hello, Sender!" << std::endl;
    char message[25];
    sprintf(message, "%s","!!!done");
    //sprintf(mess2, "%s%d%s", "s_a!!!",1,"!!!done");
    char *mobile_IP="127.0.0.1";
    //char *mobile_IP="10.171.12.249";

    //sendto_udp(mobile_IP, message);
    //sendto_udp_broadcast(mobile_IP, mess2);

   /* pkt_to_send->id=12;
    pkt_to_send->tx_time=14;
    pkt_to_send->lat=1;
    pkt_to_send->lon=2;
    pkt_to_send->alt=3;*/
    pkt_to_send->id=12;
    pkt_to_send->tx_time=14.31224;
    pkt_to_send->lat=1.12445;
    pkt_to_send->lon=-2.1234124;
    pkt_to_send->alt=3.141234;

    //sendto_udp_struct(mobile_IP, pkt_to_send);
    sendto_udp_struct_broadcast(pkt_to_send);
    /*

    printf("Here is the message: id = %d, tx_time = %f s , lat=%f , lon=%f \n",pkt_to_send->id,
           pkt_to_send->tx_time,pkt_to_send->lat,pkt_to_send->lon);

   */


    return 0;
}