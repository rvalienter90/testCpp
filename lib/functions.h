/*
 * functions.h
 *
 *  Created on: Nov 14, 2018
 *      Author: rodolfo
 */
#include <stdio.h>
#include <byteswap.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#define mytype double
#define mytype2 int
mytype ReverseType( mytype  value );
mytype2 ReverseType_mytype2( mytype2  value );
#define speficier "%lf"
//bsm_NSL* mybsm;
/*
 #define speficier "%d"
#define mytype u_int8_t
 //basic u_int8_t
typedef struct custom_bsm
{
	mytype id;
	mytype tx_time;
}CUSTOM_bsm;

unsigned long  getMicrotime();
void ini_bsm(CUSTOM_bsm*mybsm, int value);
void update_bsm(CUSTOM_bsm*mybsm,CUSTOM_bsm newbsm);
void print_bsm(CUSTOM_bsm*mybsm);
int encode_bsm(char*,CUSTOM_bsm*);

void ini_bsm(CUSTOM_bsm*mybsm, int value){

	mybsm->id=value;
	mybsm->tx_time=value;

}

void print_bsm(CUSTOM_bsm*mybsm){

	printf("id =" speficier " tx_time = " speficier,mybsm->id, mybsm->tx_time);

}

int encode_bsm(char*datastr,CUSTOM_bsm*mybsm){


	int n;
	n=sprintf (datastr, "id " speficier " tx_time " speficier ,mybsm->id, mybsm->tx_time);
	return n;

}

*/


//u_int64_t

//#define swap(a) bswap_32(a)
#define swap(a) ReverseType(a)
#define swap_int(a) ReverseType_mytype2(a)
struct custom_bsm_mytype {
	mytype 	id;
	mytype  tx_time;
	mytype  lat;
	mytype  lon;
	mytype  alt;
	mytype  speed;
	mytype 	coll_flag;
	mytype 	bkoff_count;
	mytype  mac_delay;
	mytype 	txPower;
	mytype 	rxPower;



}__attribute__((__packed__));
struct custom_bsm {
	int 	id;
	mytype  tx_time;
	mytype  lat;
	mytype  lon;
	mytype  alt;
	mytype  speed;
	mytype 	coll_flag;
	mytype 	bkoff_count;
	mytype  mac_delay;
	mytype 	txPower;
	mytype 	rxPower;

}__attribute__((__packed__));
struct custom_bsm_ok {
	int  	id;
	long double  tx_time;
	long double   lat;
	long double   lon;
	long double   alt;
	long double   speed;
	int 	coll_flag;
	int 	bkoff_count;
	long  mac_delay;
	double 	txPower;
	double 	rxPower;

}__attribute__((__packed__));
typedef struct custom_bsm  CUSTOM_bsm ;
typedef struct custom_bsm_mytype  CUSTOM_bsm_mytype ;
unsigned long  getMicrotime();
void ini_bsm(CUSTOM_bsm*mybsm, int value);
//void update_bsm(CUSTOM_bsm*mybsm,CUSTOM_bsm newbsm);
void print_bsm(CUSTOM_bsm*mybsm);
void print_bsm_full(CUSTOM_bsm*mybsm);
int encode_bsm(char*,CUSTOM_bsm*);
void check_endian();
void change_endian(CUSTOM_bsm*mybsm);
int decode_bsm(char*,CUSTOM_bsm*);
void update_bsm(CUSTOM_bsm*mybsm,CUSTOM_bsm newbsm);


/*
//long
typedef struct custom_bsm {
	int id;
	long  tx_time;
	long  lat;
	long  lon;
	long  alt;
	long  speed;
	int coll_flag;
	int bkoff_count;
	long  mac_delay;
	long txPower;
	long rxPower;
} CUSTOM_bsm ;

unsigned long  getMicrotime();
void ini_bsm(CUSTOM_bsm*mybsm, int value);
void update_bsm(CUSTOM_bsm*mybsm,CUSTOM_bsm newbsm);
void print_bsm(CUSTOM_bsm*mybsm);
int encode_bsm(char*,CUSTOM_bsm*);



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

void print_bsm(CUSTOM_bsm*mybsm){

	printf("id = %d, tx_time = %ld,lat= %ld, lon= %ld , alt= %ld , speed= %ld, coll_flag= %d , bkoff_count= %d, mac_delay= %ld, txPower= %ld,rxPower= %ld \n",
			mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
			,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);

}

int encode_bsm(char*datastr,CUSTOM_bsm*mybsm){


	int n;
	n=sprintf (datastr, "id %d tx_time %ld lat %ld lon %ld alt %ld speed %ld coll_flag %d "
			"bkoff_count %d mac_delay %ld txPower %ld rxPower %ld",
			mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
			,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);
	return n;

}
*/

/*

 //long double
typedef struct custom_bsm {
	invoid ini_bsm(CUSTOM_bsm*mybsm, int value){

	mybsm->id=value;
	mybsm->tx_time=value;
	mybsm->lat=value;
	mybsm->lon=value;
	mybsm->alt=value;
	mybsm->speed=value;
	mybsm->coll_flag=int)value;
	mybsm->bkoff_count=value;
	mybsm->mac_delay=value;
	mybsm->txPower=value;
	mybsm->rxPower=value;

}t id;
	long double tx_time;
	long double lat;
	long double lon;
	long double alt;
	long double speed;
	int coll_flag;
	int bkoff_count;
	long double mac_delay;
	double txPower;
	double rxPower;
} CUSTOM_bsm ;
unsigned long  getMicrotime();
void ini_bsm(CUSTOM_bsm*mybsm, int value);
void update_bsm(CUSTOM_bsm*mybsm,CUSTOM_bsm newbsm);
void print_bsm(CUSTOM_bsm*mybsm);
int encode_bsm(char*,CUSTOM_bsm*);

void ini_bsm(CUSTOM_bsm*mybsm, int value){

	mybsm->id=(int)value;
	mybsm->tx_time=(long double)value;
	mybsm->lat=(long double)value;
	mybsm->lon=(long double)value;
	mybsm->alt=(long double)value;
	mybsm->speed=(long double)value;
	mybsm->coll_flag=(int)value;
	mybsm->bkoff_count=(int)value;
	mybsm->mac_delay=(long double)value;
	mybsm->txPower=(double)value;
	mybsm->rxPower=(double)value;

}

void print_bsm(CUSTOM_bsm*mybsm){

	printf("id = %d, tx_time = %Lf,lat= %Lf, lon= %Lf , alt= %Lf , speed= %Lf, coll_flag= %d , bkoff_count= %d, mac_delay= %Lf, txPower= %f,rxPower= %f \n",
			mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
			,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);

}

int encode_bsm(char*datastr,CUSTOM_bsm*mybsm){


	int n;
	n=sprintf (datastr, "id %d tx_time %Lf lat %Lf lon %Lf alt %Lf speed %Lf coll_flag %d "
			"bkoff_count %d mac_delay %Lf txPower %f rxPower %f",
			mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
			,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);
	return n;

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

}*/

/*
 //long double and int
typedef struct custom_bsm {
	u_int32_t id;
	u_int64_t tx_time;
	u_int64_t lat;
	u_int64_t lon;
	u_int64_t alt;gettimeofday
	u_int64_t speed;
	u_int32_t coll_flag;
	u_int32_t bkoff_count;
	u_int64_t mac_delay;
	u_int64_t txPower;
	u_int64_t rxPower;
} CUSTOM_bsm ;
unsigned long  getMicrotime();
void ini_bsm(CUSTOM_bsm*mybsm, int value);
void update_bsm(CUSTOM_bsm*mybsm,CUSTOM_bsm newbsm);
void print_bsm(CUSTOM_bsm*mybsm);
int encode_bsm(char*,CUSTOM_bsm*);
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
void print_bsm(CUSTOM_bsm*mybsm){

	printf("id = %u, tx_time = %u,lat= %lu, lon= %lu , alt= %lu , speed= %lu, coll_flag= %u , bkoff_count= %u, mac_delay= %lu, txPower= %lu,rxPower= %lu \n",
			mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
			,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);

}

int encode_bsm(char*datastr,CUSTOM_bsm*mybsm){


	int n;
	n=sprintf (datastr, "id %d tx_time %lu lat %lu lon %lu alt %lu speed %lu coll_flag %lu "
			"bkoff_count %d mac_delay %lu txPower %lu rxPower %lu",
			mybsm->id, mybsm->tx_time,mybsm->lat,mybsm->lon,mybsm->alt,	mybsm->speed,mybsm->coll_flag
			,mybsm->bkoff_count,mybsm->mac_delay,mybsm->txPower,mybsm->rxPower);
	return n;

}





*/

/*
void change_endian_specific(CUSTOM_bsm*mybsm){

	mybsm->id=bswap_32(mybsm->id);
	mybsm->tx_time=bswap_64(mybsm->tx_time);
	mybsm->lat=bswap_64(mybsm->lat);
	mybsm->lon=bswap_64(mybsm->lon);
	mybsm->alt=bswap_64(mybsm->alt);
	mybsm->speed=bswap_64(mybsm->speed);
	mybsm->coll_flag=bswap_32(mybsm->coll_flag);
	mybsm->bkoff_count=bswap_32(mybsm->bkoff_count);
	mybsm->mac_delay=bswap_64(mybsm->mac_delay);
	mybsm->txPower=bswap_64(mybsm->txPower);
	mybsm->rxPower=bswap_64(mybsm->rxPower);



}*/
#endif /* FUNCTIONS_H_ */
