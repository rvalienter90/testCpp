/*
 * comsim_eth.h
 *
 *  Created on: Nov 15, 2018
 *      Author: rodolfo
 */

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
#include "functions.h"
#include <math.h>



#ifndef COMSIM_ETH_H_
#define COMSIM_ETH_H_
int start_com(char * ip,int port, int *sock, struct sockaddr_in *server);
void end_com(int *sock);
int send_pkg(CUSTOM_bsm* mybsm, int *sock,struct sockaddr_in *server);
void My_error(const char *msg);


#endif /* COMSIM_ETH_H_ */
