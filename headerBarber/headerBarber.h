#include<stdio.h>
#include<stdlib.h>
#include "windows.h"
#include<string.h>
#define true 1
#define false 0

typedef struct tElmtBarber *addressBarber;
typedef struct tElmtBarber{
    int nomorAnt;
    int paketBarber;
    char* nama;
    addressBarber next;
}bar;

typedef struct{
    addressBarber head;
    addressBarber tail;
}Queue;

typedef struct tElmtRiwBar *addressRiwayat;
typedef struct tElmtRiwBar{
    int paketBarber;
    char* nama;
    addressRiwayat next;
}riw;

typedef struct{
    addressRiwayat First;
}ListRiwayat;

void createEmpty(Queue *Q);
addressBarber alokasiBarber(int nomorAntX, int paketBarberX, char* namaX);
void dealokasi(addressBarber p);
boolean isEmpty(Queue Q);
void addAddress(Queue *Q, addressBarber p);
void add(Queue *Q,int nomorAntX, int paketBarberX, char* namaX);
void del(Queue *Q,int* nomorAntX, int* paketBarberX, char* namaX);

//list linier
void createListBar(ListRiwayat *LR);
addressRiwayat alokasiRiwayat(int paketBarberX, char* namaX);
void insertFirst(ListRiwayat *LR, addressRiwayat p);
void insertLast (ListRiwayat *LR, addressRiwayat p);
void cetakRiwayat(ListRiwayat LR);
void insertData (ListRiwayat *LR, addressRiwayat p);
