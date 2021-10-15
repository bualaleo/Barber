#include<stdio.h>
#include "headerBarber.h"
#include<string.h>

void createEmpty(Queue *Q){
    (*Q).head = NULL;
    (*Q).tail = NULL ;
}
addressBarber alokasiBarber(int nomorAntX, int paketBarberX, char* namaX){
    addressBarber p = (addressBarber)malloc(sizeof(bar));
    if(p!=NULL){
        (p)->nomorAnt = nomorAntX;
        (p)->paketBarber = paketBarberX;
        (p)->nama = namaX;
        (p)->next = NULL;
    }
    return p;
}

void dealokasi(addressBarber p){
    free(p);
}

boolean isEmpty(Queue Q){
    if(Q.head == NULL){
        return true;
    } else {
        return false;
    }
}

void addAddress(Queue *Q, addressBarber p){
    if(isEmpty(*Q)){
        (*Q).head = p;
        (*Q).tail = p;
    } else {
        (*Q).tail->next = p;
        (*Q).tail = p;
    }
}

void add(Queue *Q,int nomorAntX, int paketBarberX, char* namaX){
    addressBarber q = alokasiBarber(nomorAntX,paketBarberX,namaX);
    addAddress(Q,q);
}

void del(Queue *Q,int* nomorAntX, int* paketBarberX, char* namaX){
    addressBarber q;
    *nomorAntX = ((*Q).head)->nomorAnt;
    strcpy(namaX,((*Q).head)->nama);
    *paketBarberX = ((*Q).head)->paketBarber;
    q = (*Q).head;
    (*Q).head = ((*Q).head)->next;
    dealokasi(q);
}

//list linier
void createListBar(ListRiwayat *LR){
    (*LR).First = NULL;
}

addressRiwayat alokasiRiwayat(int paketBarberX, char* namaX){
    addressRiwayat p;
    p = (addressRiwayat)malloc(sizeof(riw));
    if(p!=NULL){
        (p)->paketBarber = paketBarberX;
        (p)->nama = namaX;
        (p)->next = NULL;
    }
    return p;
}

void insertFirst(ListRiwayat *LR, addressRiwayat p){
    if((*LR).First==NULL){
        (*LR).First = p;
    } else {
        p->next = (*LR).First;
        (*LR).First = p;
    }
}

void insertLast (ListRiwayat *LR, addressRiwayat p){
    addressRiwayat a;
    if((*LR).First==NULL){
        (*LR).First = p;
    } else {
        a = (*LR).First;
        while (a->next!=NULL){
            a = a->next;
        }
        a->next = p;
    }
}


void insertData (ListRiwayat *LR, addressRiwayat p){
    if((*LR).First==NULL){
        insertFirst((&*LR),p);
    } else {
        insertLast((&*LR), p);
    }
}



