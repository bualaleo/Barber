#include <stdio.h>
#include "Barber.c"

void daftar(Queue *qm, ListRiwayat *LR,int nomorAntri){
        system("cls");
        printf("\n\t\t\t\t             Daftar Paket BarberShop         \n\n");
        printf("\t\t\t\t===============================================\n\n");
        printf("\t\t\t\t|No. | Paket               |       Harga      |\t\t\n");
        printf("\t\t\t\t-----------------------------------------------\n");
        printf("\t\t\t\t| 1  | Hair Cut            |       Rp. 60000  |\t\t\n");
        printf("\t\t\t\t| 2  | Shave               |       Rp. 30000  |\t\t\n");
        printf("\t\t\t\t| 3  | Massage             |       Rp. 35000  |\t\t\n");
        printf("\t\t\t\t| 4  | Shampoo             |       Rp. 20000  |\t\t\n");
        printf("\t\t\t\t| 5  | Creambath           |       Rp. 70000  |\t\t\n");
        printf("\t\t\t\t| 6  | Hair Dyeing         |       Rp. 100000 |\t\t\n");
        printf("\t\t\t\t| 7  | Face Mask           |       Rp. 60000  |\t\t\n");
        printf("\t\t\t\t| 8  | Manicure            |       Rp. 20000  |\t\t\n");
        printf("\t\t\t\t| 9  | Pedicure            |       Rp. 30000  |\t\t\n");
        printf("\t\t\t\t| 10 | Ear Cleaning        |       Rp. 30000  |\t\t\n");
        printf("\t\t\t\t| 11 | Ft Reflexology      |       Rp. 50000  |\t\t\n");
        printf("\t\t\t\t| 12 | Traditional Massage |       Rp. 50000  |\t\t\n");
        printf("\n\t\t\t\t=============================================\n");

        int paket;
        char *nm;
        nm=malloc(256);
        printf("\n");
        printf("Masukkan Nama : ");
        scanf("%255s", nm);
        printf("Pilihan Paket : ");
        scanf("%d",&paket);

        add(&*qm, nomorAntri, paket, nm);

        addressRiwayat b = alokasiRiwayat(paket, nm);
        insertData(&*LR, b);

}

void lihatAntrian(Queue qm){
    while(!isEmpty(qm)){
        printf("\nnomor antrian  : %d , %d,  %s\n", qm.head->nomorAnt, qm.head->paketBarber, qm.head->nama);
        (qm).head = ((qm).head)->next;
    }
}

void lihatRiwayat(ListRiwayat LR){
     addressRiwayat a = LR.First;
        while (a!=NULL){
            printf("Paket %d  Nama  %s\n",a->paketBarber, a->nama);
        a = a->next;
    }

}

void nextAntrian(Queue *qm){
    addressBarber q=(*qm).head;
    if(q!=NULL){
    (*qm).head = ((*qm).head)->next;
    dealokasi(q);
    }
}


void menuUtama(Queue qm, ListRiwayat LR,int nomorAntri){
    int pilih;
    do{
        system("cls");
        printf("\n\n\n\t\t\t==================================================================\n");
        printf("\t\t\t===============   Selamat datang di BarberShop    ================ \n");
        printf("\t\t\t==================================================================\n\n");
        printf("\t\t\t===============   Daftar Antrian    ================ \n");
        printf("\t\t\t==================================================================\n\n");


        lihatAntrian(qm);



        printf("\t\t\t==================================================================\n\n");
        printf("\n\t\t\t\t\t1. Daftar \n");
        printf("\n\t\t\t\t\t2. Next Antrian \n");
        printf("\n\t\t\t\t\t3. Lihat Riwayat \n");
        printf("\n\t\t\t\t\t4. Exit \n");
        printf("\t\t\t__________________________________________________________________\n");
        printf("\n\t\t\t\tSilahkan pilih yang ingin anda inginkan : ");
        scanf("%d",&pilih);
        printf("\n\t\t\t\t");

        switch(pilih){
            case 1:daftar(&qm,&LR,nomorAntri);nomorAntri+=1;getchar();;break;
            case 2:nextAntrian(&qm);;break;
            case 3:lihatRiwayat(LR);getchar();;break;
            case 4:exit(0);getchar();;break;
            default:printf("Pilihan Yang Anda Masukkan Salah");break;
        }
    }while(pilih < 1 || pilih > 4);
     getchar();
     menuUtama(qm,LR,nomorAntri);





}



int main(){
    int nomorAntri=1;
    Queue qm;
    ListRiwayat LR;
    createEmpty(&qm);
    createListBar(&LR);

    menuUtama(qm,LR,nomorAntri);


    return 0;
}
