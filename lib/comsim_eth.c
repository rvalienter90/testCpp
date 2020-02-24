//
// Created by nsl on 4/22/19.
//
#include "comsim_eth.h"
int start_com(char * ip,int port, int *sock, struct sockaddr_in *server)
{
    //char * ip="192.168.0.40";
    //int port=2000;
    printf("Start client\n");

    //struct sockaddr_in server;
    struct hostent *hp;
    //char buffer[256];
    //u_int8_t i,j;

    //CUSTOM_bsm* mybsm;
    //mybsm= (struct custom_bsm *) calloc(1,1 * sizeof(CUSTOM_bsm));
    printf("Size pkg %lu\n",sizeof(CUSTOM_bsm));
    *sock= socket(AF_INET, SOCK_DGRAM, 0);
    if (*sock < 0) My_error("socket");
    int broadcast = 1;

    //     This option is needed on the socket in order to be able to receive broadcast messages
    //   If not set the receiver will not receive broadcast messages in the local network.

    if(setsockopt(*sock, SOL_SOCKET, SO_BROADCAST,&broadcast,sizeof(broadcast)) < 0)
    {
        printf("Error in setting Broadcast option");
        close(*sock);
        return 0;
    }

    server->sin_family = AF_INET;
    hp = gethostbyname(ip);
    if (hp==0) My_error("Unknown host");
    bcopy((char *)hp->h_addr,(char *)&server->sin_addr,hp->h_length);
    server->sin_port = htons(port);
    //unsigned int length=sizeof(struct sockaddr_in);

    printf("Ready to send the Packets from client to server\n");
    return 1;

}

void end_com(int *sock){
    close(*sock);
}

int send_pkg(CUSTOM_bsm* mybsm, int *sock,struct sockaddr_in *server){
    int n;
    int print_flag=0;
    if (print_flag==1)
        printf("Transmiting \n");
    //print_bsm(mybsm);
    CUSTOM_bsm* pkt_to_send_tmp = (CUSTOM_bsm*) calloc(1,1 * sizeof(CUSTOM_bsm));
    update_bsm(pkt_to_send_tmp, *mybsm);
    change_endian(pkt_to_send_tmp);
    //printf("Size pkg %lu\n",sizeof(mybsm));
    n=sendto(*sock,pkt_to_send_tmp,sizeof(CUSTOM_bsm),0,(const struct sockaddr *)server,sizeof(struct sockaddr_in));
    //printf("n = %E\n", n);
    if (n < 0){
        printf("No Transmited \n");
        My_error("Sendto");
        return 0;
    }
    if (print_flag==1)
        printf("Transmited \n");
    return 1;

}

void My_error(const char *msg)
{
    perror(msg);
    exit(0);
}