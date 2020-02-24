//
// Created by nsl on 2/24/20.
//

struct addrinfo hints;
struct addrinfo *serverinfo;
memset(&hints,0,sizeof hints);
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_DGRAM;
hints.ai_flags = AI_PASSIVE;

int status = getaddrinfo(NULL, port, &hints, &serverinfo);
int sock = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);
status = bind(sock, serverinfo->ai_addr, serverinfo->ai_addrlen);
freeaddrinfo(serverinfo);

// poll until there's an incoming packet

struct sockaddr sender;
socklen_t sendsize = sizeof(sender);
bzero(&sender, sizeof(sender));

recvfrom(sock, message, sizeof(message), 0, &sender, &sendsize);

// message processing

sendto(sock, response, sizeof(response), 0, (struct sockaddr *)&sender, sendsize);



//or
struct sockaddr_storage sender;
socklen_t sendsize = sizeof(sender);
bzero(&sender, sizeof(sender));

recvfrom(sock, message, sizeof(message), 0, (struct sockaddr*)&sender, &sendsize);


mobile_IP="192.168.1.100";


struct sockaddr_in serv_addr;
struct hostent *server;

int port = 12001;
/*
                                   //char buffer[256];
                                   info* pkt_to_send;
                                   pkt_to_send = (info*) malloc(1 * sizeof(info));

                                   pkt_to_send->id = 1;
                                   pkt_to_send->flag = 2;
                                   pkt_to_send->X = 2.56758;
                                   pkt_to_send->Y = 3.123454647;*/


portno = port;
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0)
printf("ERROR opening socket\n");
//perror("ERROR opening socket");
server = gethostbyname(mobile_IP);
if (server == NULL) {
//fprintf(stderr,"ERROR, no such host\n");
//perror("ERROR, no such host\n");
printf("ERROR, no such host\n");
//exit(0);
}
bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
bcopy((char *)server->h_addr,
(char *)&serv_addr.sin_addr.s_addr,
server->h_length);
serv_addr.sin_port = htons(portno);
if (domConfig.print_debug==1){
printf("  Connecting\n");
}
if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
printf("ERROR connecting\n");



info* pkt_to_sendHV;
pkt_to_sendHV = (info*) malloc(1 * sizeof(info));
pkt_to_sendHV->id = 1;
pkt_to_sendHV->end = 0;
pkt_to_sendHV->flag = 0;
pkt_to_sendHV->X = hvData.enuM.X;
pkt_to_sendHV->Y = hvData.enuM.Y;



printf("Sending the Packet from client to server\n");
n = write(sockfd,pkt_to_sendHV,sizeof(info));
if (n < 0)
printf("ERROR writing to socket\n");


int sendto_pc(char *mobile_IP, char *message)
{

    // initialize socket and portnumber
    int sock;
    int portNumber = 12001;

    // open UDP socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("pas 1\n"); return 1;}

    // set Mobile IP Address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(mobile_IP);
    addr.sin_port = htons(portNumber);

    // send message to location
    if (sendto( sock, message, strlen(message), 0,(struct sockaddr *) &addr, sizeof(addr)) < 0)
    {
        perror("sendto");
        //exit(1);  ***********ERROR was causing application crash
    }

    return 0;

}



int sockfd, portno, n;

void send_1_pkgto_pc(char *host,info *pkt_to_send){

    if (domConfig.print_debug==1){
        printf("  In send_1_pkgto_pc\n");
    }
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    int port = 12001;
    /*
        //char buffer[256];
        info* pkt_to_send;
        pkt_to_send = (info*) malloc(1 * sizeof(info));

        pkt_to_send->id = 1;
        pkt_to_send->flag = 2;
        pkt_to_send->X = 2.56758;
        pkt_to_send->Y = 3.123454647;*/


    portno = port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        printf("ERROR opening socket\n");
    //perror("ERROR opening socket");
    server = gethostbyname(host);
    if (server == NULL) {
        //fprintf(stderr,"ERROR, no such host\n");
        //perror("ERROR, no such host\n");
        printf("ERROR, no such host\n");
        //exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    if (domConfig.print_debug==1){
        printf("  Connecting\n");
    }
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        printf("ERROR connecting\n");
    //perror("ERROR connecting");
    //printf("Please enter the message: ");
    //bzero(buffer,256);
    //fgets(buffer,255,stdin);

    printf("Sending the Packet from client to server\n");
    n = write(sockfd,pkt_to_send,sizeof(info));
    if (n < 0)
        printf("ERROR writing to socket\n");
    //perror("ERROR writing to socket");
    close(sockfd);


}


char mess2[25];

sprintf(mess2, "%s%d%s", "s_a!!!",ALERT_COUNT,"!!!done");
sendto_tablet1(mobile_IP, mess2);

int sendto_tablet1(char *mobile_IP, char *message)
{

    // initialize socket and portnumber
    int sock;
    int portNumber = 12001;

    // open UDP socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("pas 1\n"); return 1;}

    // set Mobile IP Address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(mobile_IP);
    addr.sin_port = htons(portNumber);

    // send message to location
    if (sendto( sock, message, strlen(message), 0,(struct sockaddr *) &addr, sizeof(addr)) < 0)
    {
        perror("sendto");
        //exit(1);  ***********ERROR was causing application crash
    }

    return 0;

}


//broadcast
int sendto_tablet1(char *mobile_IP, char *message)
{

    // initialize socket and portnumber
    int sock;
    int portNumber = 12001;

    // open UDP socket
    if((sock=socket(AF_INET,SOCK_DGRAM,0))==-1) {printf("pas 1\n"); return 1;}
    // Bilal: set broadcast permissions, return if fail
    int broadcastEnable = 1;
    int ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret == -1) {printf("pas 1\n"); return 1;}

    // set Mobile IP Address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_BROADCAST); // Bilal: for broadcast need to use this code
    addr.sin_port = htons(portNumber);

    // send message to location
    if (sendto( sock, message, strlen(message), 0,(struct sockaddr *) &addr, sizeof(addr)) < 0)
    {
        perror("sendto");
        //exit(1);  ***********ERROR was causing application crash
    }

    close(sock);

    return 0;

}



/* Create a socket to send UDP messages to PC and returns the socket.
 * Fills destination PC address in udpTxAddr.
 */
int dwmhCreateTxSock(struct sockaddr_in *udpTxAddr, wint8 *ipAddr, wuint32 portNum)
{
    int sock;
    wuint8 IP[4];

    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        V2X_LOG(LOG_ERR, "Error : Could not create UDP OBE2PC socket. %s\n", strerror(errno));
        return -1;
    }

    memset(udpTxAddr, 0, sizeof(*udpTxAddr));
    udpTxAddr->sin_family = AF_INET;
    udpTxAddr->sin_addr.s_addr = inet_addr(ipAddr);
    udpTxAddr->sin_port = htons(portNum);

    sscanf(ipAddr, "%hhu.%hhu.%hhu.%hhu", &IP[0], &IP[1], &IP[2], &IP[3]);
    if (IP[3] == 255) { /* broadcast */
        int broadc = 1;
        if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadc, sizeof(broadc)) == -1) {
            V2X_LOG(LOG_ERR, "Error : set broadcast option failed on Tx socket : %s\n",
                    strerror(errno));
            close(sock);
            return -1;
        }
    }

    return sock;
}

/* send UDP data (in Raw or Meta format) from OBE to PC */
void dwmhTxUDP(cfg_wmh_t *cfg_wmh_ptr, dwmhDataT *dwmhData, void *WSM, WBOOL isTx)
{
    static WBOOL init = WTRUE;
    static int udpOBE2PCSock = -1;
    static struct sockaddr_in udpTxAddr;
    wuint8 UDPTxBuf[DWMH_MAX_LOGBUF_SIZE];
    dwmhOBE2PCUDPPktT udpTxPkt;
    outWSMV2Type *dwmhTxWSM = NULL;
    inWSMV2Type  *rxWSM = NULL;

    if (!cfg_wmh_ptr->UDPMode) {
        return;
    }


    if (init) {
        init = WFALSE;

        /* Create UDP OBE2PC socket */
        if ((udpOBE2PCSock = dwmhCreateTxSock(&udpTxAddr, cfg_wmh_ptr->wsm_obe2pc_ip, cfg_wmh_ptr->wsm_obe2pc_port)) == -1) {
            return;
        }
    }

    if (udpOBE2PCSock == -1) {
        return;
    }

    /* this if-else is done so we don't need two separate functions to
     * process outWSMV2Type and inWSMV2Type
     */
    if (isTx) {
        dwmhTxWSM = WSM;

        memset(udpTxPkt.peerMAC, 0, sizeof(udpTxPkt.peerMAC));
        udpTxPkt.rssi     = 0;
        udpTxPkt.chanNum  = dwmhTxWSM->channelNumber;
        udpTxPkt.dataRate = dwmhTxWSM->dataRate;
        udpTxPkt.txPwr    = dwmhTxWSM->txPwrLevel;
        udpTxPkt.psid     = dwmhTxWSM->psid;
        udpTxPkt.dataLen  = htons(dwmhTxWSM->dataLength);
    } else {
        rxWSM = WSM;

        memcpy(udpTxPkt.peerMAC, rxWSM->srcMacAddress, sizeof(udpTxPkt.peerMAC));
        udpTxPkt.rssi     = rxWSM->rss;
        udpTxPkt.chanNum  = rxWSM->channelNumber;
        udpTxPkt.dataRate = rxWSM->dataRate;
        udpTxPkt.txPwr    = rxWSM->txPwrLevel;
        udpTxPkt.psid     = rxWSM->psid;
        udpTxPkt.dataLen  = htons(rxWSM->dataLength);
    }

    udpTxPkt.msgType = isTx;
    WSU_SEM_LOCKR(&shm_wmh_ptr->h.ch_lock);
    if (cfg_wmh_ptr->chanMode == V2V_CHAN_CONT) {
        udpTxPkt.chanBusyRatio = shm_wmh_ptr->statData.rawChanBusy.valid ?
                                 shm_wmh_ptr->statData.rawChanBusy.val : 0 ;
    } else {
        udpTxPkt.chanBusyRatio = shm_wmh_ptr->statData.CCHBusy.valid ?
                                 shm_wmh_ptr->statData.CCHBusy.val : 0 ;
    }
    WSU_SEM_UNLOCKR(&shm_wmh_ptr->h.ch_lock);

    udpTxPkt.safetySupp = dwmhData->safetySupp.valid ? dwmhData->safetySupp.val :
                          DWMH_UDP_INVALID_SAFETYSUPP;

    udpTxPkt.dataFormat = cfg_wmh_ptr->UDPFormat;
    if (cfg_wmh_ptr->UDPFormat == V2V_DWMH_UDP_META) {
        dwmhLogCreateCSV(dwmhData, UDPTxBuf);
        udpTxPkt.dataLen = htons(strlen(UDPTxBuf));
        memcpy(udpTxPkt.data, UDPTxBuf, strlen(UDPTxBuf));
    } else if (cfg_wmh_ptr->UDPFormat == V2V_DWMH_UDP_RAW) {
        if (isTx) {
            memcpy(udpTxPkt.data, dwmhTxWSM->data, dwmhTxWSM->dataLength);
        } else {
            memcpy(udpTxPkt.data, rxWSM->data, rxWSM->dataLength);
        }
    }

    if (sendto(udpOBE2PCSock, &udpTxPkt,
               (sizeof(udpTxPkt) - sizeof(udpTxPkt.data) + udpTxPkt.dataLen), 0,
               (struct sockaddr *)&udpTxAddr, sizeof(udpTxAddr)) < 0) {
        V2X_LOG(LOG_ERR, "Error : UDP Tx sendto failed. %s\n", strerror(errno));
    }

    return;
}


