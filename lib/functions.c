/*
 * functions.c
 *
 *  Created on: Nov 14, 2018
 *      Author: rodolfo
 */

#include "functions.h"


void ini_bsm_mytype(CUSTOM_bsm*mybsm, mytype value){

    mybsm->id=value;
    mybsm->tx_time=value;
    mybsm->lat=value;
    mybsm->lon=value;
    mybsm->alt=value;
    mybsm->speed=value;
    mybsm->coll_flag=value;
    mybsm->bkoff_count=value;
    mybsm->mac_delay=value;
    mybsm->txPower=value;
    mybsm->rxPower=value;

}
void ini_bsm(CUSTOM_bsm*mybsm, int value){

    mybsm->id=value;
    mybsm->tx_time=value;
    mybsm->lat=value;
    mybsm->lon=value;
    mybsm->alt=value;
    mybsm->speed=value;
    mybsm->coll_flag=value;
    mybsm->bkoff_count=value;
    mybsm->mac_delay=value;
    mybsm->txPower=value;
    mybsm->rxPower=value;

}
void update_bsm(CUSTOM_bsm*mybsm,CUSTOM_bsm newbsm){

    mybsm->id=newbsm.id;
    mybsm->tx_time=newbsm.tx_time;
    mybsm->lat=newbsm.lat;
    mybsm->lon=newbsm.lon;
    mybsm->alt=newbsm.alt;
    mybsm->speed=newbsm.speed;
    mybsm->coll_flag=newbsm.coll_flag;
    mybsm->bkoff_count=newbsm.bkoff_count;
    mybsm->mac_delay=newbsm.mac_delay;
    mybsm->txPower=newbsm.txPower;
    mybsm->rxPower=newbsm.rxPower;

}
void print_bsm_mytype(CUSTOM_bsm_mytype*mybsm){

    printf("id = " speficier  " \n tx_time = " speficier "\n lat= " speficier " \n lon= " speficier "\n  alt= " speficier " \n speed= " speficier
           " \n coll_flag= " speficier " \n bkoff_count= " speficier " \n mac_delay= " speficier " \n txPower= " speficier "\n  rxPower= " speficier "  \n",
           mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
            ,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);

}
void print_bsm(CUSTOM_bsm*mybsm){

    printf(" id = %u \n tx_time = " speficier "\n lat= " speficier " \n lon= " speficier "\n alt= " speficier " \n speed= " speficier
           " \n txPower= " speficier "\n rxPower= " speficier "  \n",
           mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->txPower,mybsm->rxPower);

}
void print_bsm_full(CUSTOM_bsm*mybsm){

    printf(" id = %u \n tx_time = " speficier "\n lat= " speficier " \n lon= " speficier "\n alt= " speficier " \n speed= " speficier
           " \n coll_flag= " speficier " \n bkoff_count= " speficier " \n mac_delay= " speficier " \n txPower= " speficier "\n rxPower= " speficier "  \n",
           mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
            ,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);

}

int encode_bsm_mytype(char*datastr,CUSTOM_bsm_mytype*mybsm){


    int n;
    n=sprintf (datastr, "id " speficier "  tx_time " speficier "  lat " speficier "  lon " speficier "  alt " speficier "  speed " speficier "  coll_flag " speficier
                        "bkoff_count " speficier "  mac_delay " speficier "  txPower " speficier "  rxPower " speficier,
               mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
            ,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);
    return n;

}
int encode_bsm(char*datastr,CUSTOM_bsm*mybsm){


    int n;
    n=sprintf (datastr, "id " "%u" "  tx_time " speficier "  lat " speficier "  lon " speficier "  alt " speficier "  speed " speficier "  coll_flag " speficier
                        "bkoff_count " speficier "  mac_delay " speficier "  txPower " speficier "  rxPower " speficier,
               mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
            ,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);
    return n;

}
int  decode_bsm_mytype(char*datastr,CUSTOM_bsm*mybsm){
    mytype id;
    mytype  tx_time;
    mytype  lat;
    mytype  lon;
    mytype  alt;
    mytype  speed;
    mytype coll_flag;
    mytype bkoff_count;
    mytype  mac_delay;
    mytype txPower;
    mytype rxPower;

    int convertions;
    convertions=sscanf (datastr, "%*s " speficier " %*s " speficier " %*s " speficier " %*s " speficier " %*s " speficier " %*s " speficier " %*s" speficier
                                 "%*s " speficier " %*s " speficier " %*s " speficier " %*s " speficier ,
                        &id, &tx_time,&lat,&lon,&alt,&speed,&coll_flag,&bkoff_count,&mac_delay,&txPower,&rxPower);


    mybsm->id=id;
    mybsm->tx_time=tx_time;
    mybsm->lat=lat;
    mybsm->lon=lon;
    mybsm->alt=alt;
    mybsm->speed=speed;
    mybsm->coll_flag=coll_flag;
    mybsm->bkoff_count=bkoff_count;
    mybsm->mac_delay=mac_delay;
    mybsm->txPower=txPower;
    mybsm->rxPower=rxPower;

    return convertions;

}
int  decode_bsm(char*datastr,CUSTOM_bsm*mybsm){
    int id;
    mytype  tx_time;
    mytype  lat;
    mytype  lon;
    mytype  alt;
    mytype  speed;
    mytype coll_flag;
    mytype bkoff_count;
    mytype  mac_delay;
    mytype txPower;
    mytype rxPower;

    int convertions;
    convertions=sscanf (datastr, "%*s " "%u" " %*s " speficier " %*s " speficier " %*s " speficier " %*s " speficier " %*s " speficier " %*s" speficier
                                 "%*s " speficier " %*s " speficier " %*s " speficier " %*s " speficier ,
                        &id, &tx_time,&lat,&lon,&alt,&speed,&coll_flag,&bkoff_count,&mac_delay,&txPower,&rxPower);


    mybsm->id=id;
    mybsm->tx_time=tx_time;
    mybsm->lat=lat;
    mybsm->lon=lon;
    mybsm->alt=alt;
    mybsm->speed=speed;
    mybsm->coll_flag=coll_flag;
    mybsm->bkoff_count=bkoff_count;
    mybsm->mac_delay=mac_delay;
    mybsm->txPower=txPower;
    mybsm->rxPower=rxPower;

    return convertions;

}
unsigned long  getMicrotime(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}
void check_endian(){
    union {
        short s;
        char c[sizeof(short)];
    }un;

    un.s = 0x0102;

    if (sizeof(short) == 2) {
        if (un.c[0] == 1 && un.c[1] == 2)
            printf("big-endian\n");

        else if (un.c[0] == 2 && un.c[1] == 1)
            printf("little-endian\n");

        else
            printf("unknown\n");
    }
    else {
        printf("sizeof(short) = %lu\n", sizeof(short));
    }
}
mytype ReverseType( mytype  value )
{
    //printf("Size %d\n",sizeof(value));
    mytype  retVal;
    char *doubleToConvert = ( char* ) & value;
    char *returndouble = ( char* ) & retVal;

    // swap the bytes into a temporary buffer
    unsigned int i;
    for (i=0; i<sizeof(value) ;i++)
        returndouble[i] = doubleToConvert[sizeof(value) -i-1];

    return  retVal;
}
mytype2 ReverseType_mytype2( mytype2  value )
{
    //printf("Size %d\n",sizeof(value));
    mytype2  retVal;
    char *doubleToConvert = ( char* ) & value;
    char *returndouble = ( char* ) & retVal;

    // swap the bytes into a temporary buffer
    unsigned int i;
    for (i=0; i<sizeof(value) ;i++)
        returndouble[i] = doubleToConvert[sizeof(value) -i-1];

    return  retVal;
}
void change_endian(CUSTOM_bsm*mybsm){

    //printf("In the change_endian() function \n");
    mybsm->id=swap_int(mybsm->id);
    mybsm->tx_time=swap(mybsm->tx_time);
    mybsm->lat=swap(mybsm->lat);
    mybsm->lon=swap(mybsm->lon);
    mybsm->alt=swap(mybsm->alt);
    mybsm->speed=swap(mybsm->speed);
    mybsm->coll_flag=swap(mybsm->coll_flag);
    mybsm->bkoff_count=swap(mybsm->bkoff_count);
    mybsm->mac_delay=swap(mybsm->mac_delay);
    mybsm->txPower=swap(mybsm->txPower);
    mybsm->rxPower=swap(mybsm->rxPower);
}



