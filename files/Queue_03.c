/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : Queue_03.c
  Tangggal  : 12 November 2014
  Deskripsi : Header untuk ADT Queue (Representasi: List Sirkular)
*/

// Library bawaan
#include "boolean.h"
#include <stdio.h>
#include "alloc.h"
#include <string.h>
#include "Queue_03.h"

// Definisi Abstract Data Type Queue
// Konstrucktor
void CreateEmptyQueue (QueueO /* output: Queue */) {
  // IS - Queue sembarang
  // FS - Membuat Antrian Sirkular dengan kapasitas tak terbatas
  //      dalam kondisi kosong
  Q->head = QueueNil;
}
// Destructor
void QueueDealokasi (QueueO /* output: Queue (self) */) {
  // IS - Q sedang dialokasi
  // FS - Q menjadi tidak terdefinisi
  // KAMUS LOKAL
  QueueAddress Adr; // temporary address
  while(!QueueIsEmpty(*Q)) {
    QueueDequeue(Q,&Adr);
    QueueElemtDealloc(&Adr);
  }
}
// Memory Management
QueueAddress QueueElemtAllocate(QueueI,QwElmI){
  // mengalokasikan elemen X kedalam memori, jika gagal maka dikembalikan nil.
  // KAMUS LOKAL
  QueueAddress EAdr;
  // ALGORITMA
  EAdr = alloc(QueueElement,1);
  if(EAdr!=QueueNil) {
    QInfo(EAdr) = X;
    QNext(EAdr) = QueueNil;
    QIndex(EAdr)= QueueCount(Q);
  } else {
    printf("failed to allocate memory --\n");
  }
  return EAdr;
}
void QueueElemtDealloc(QwAdrO){
  // melepaskan Adr ke memori
  // ALGORITMA
  free(*Adr);
}
// Validatory Check
// Selecktor
  // SELECKTOR KAPASITAS
  int  QueueCount  (QueueI /* Single Queue */) {
    // Mengirimkan banyaknya elemen di queue
    // KAMUS LOKAL
    QueueAddress CAdr;
    int     n;
    // ALGORITMA
    if(!QueueIsEmpty(Q)){
      CAdr = QHead(Q);
      do {
        CAdr = QNext(CAdr);
        n++;
      } while(CAdr != QHead(Q));
    } else {
      n = 0;
    }
    return n;
  }
  // SELECKTOR INDEKS
  // SELECKTOR ALIASES
// Setter
  // SETTER DEFINITION
  // SETTER ALIASES
// Aritmethic Operators
// Comparable Operators
// Predicate Functions
bool QueueIsEmpty(QueueI /* Single Queue */) {
  // Mengecek apakah Head-Tail dari Queue tersebut adalah nil
  return(QHead(Q)==QueueNil)&&(QTail(Q)==QueueNil);
}
bool QueueIsAlone(QueueI /* Single Queue */) {
  // Mengecek apakah Queue tersebut adalah antrian yang sendirian
  return (!QueueIsEmpty(Q)) ? (QHead(Q) == QNext(QHead(Q))) : false;
}
bool QueueIsFull (QueueI /* Single Queue */) {
  // Mengecek apakah Tail dari Queue tersebut sudah menyentuh MaxEl atau tidak
  return(false);
}
bool QueueIsFirstHead(QueueI /* Single Queue */) {
  // Mengecek apakah suatu queue memiliki head yang sesuai dengan head yang awal
  return QIndex(QHead(Q))==0;
}
// Basic Functions
void QueueAddElmt(QueueO,QwElmI /* QueueOut-SingleElement */) {
  // Menambahkan elemen X pada Queue Q paling belakang
  // IS - Q tidak penuh
  // FS - X adalah Tail yang baru, dengan arahan Tail berubah
  // KAMUS LOKAL
  QueueAddress CAdr, EAdr;
  if(QueueIsFull(*Q)){
    printf("Antrian sudah penuh!\n");
  } else {
    EAdr = QueueElemtAllocate(*Q,X);
    if (EAdr != QueueNil)
      QueueAddAddr(Q,EAdr);
  }
}
void QueueAddAddr(QueueO,QwAdrI /* QueueOut-SingleAddress */) {
  // Menyisipkan address Adr pada Queue Q paling belakang
  // IS - Q tidak penuh, dan head,adr terdefinisi
  // FS - Adr adalah alamat yang baru.
  // KAMUS LOKAL
  QueueAddress CAdr;
  // ALGORITMA
  CAdr = QHead(*Q);
  if (CAdr == QueueNil) {
    QHead(*Q) = Adr;    // Notice that Head-Base can't shifted easily
  } else {
    while(QNext(CAdr) != QHead(*Q))
      CAdr = QNext(CAdr);
    QNext(Adr)  = QNext(CAdr);
    QNext(CAdr) = Adr;
  }
}
void QueueDequeue(QueueO,QwAdrO /* QueueOut-ReturnAddress */) {
  // Membuang elemen pertama pada Q, dengan aturan FIFO
  // IS - Q harus terisi
  // FS - Adr adalah alamat kepada elemen pertama pada queue,
  //      Next dari Adr akan dimatikan menjadi nil.
  // KAMUS LOKAL
  int i;
  QueueAddress CAdr;
  QueueInfoType temp;
  // ALGORITMA
  if(QueueIsEmpty(*Q)){
    printf("Antrian masih kosong! Tambah Antrian terlebih dahulu\n");
  } else {
    *Adr = QHead(*Q);
    if(QueueIsAlone(*Q)) { // Antrian tepat 1 elemen
      QHead(*Q) = QNext(QHead(*Q)) = QueueNil;
    } else { // Antrian tidak kurang dari 2 elemen
      CAdr = QHead(*Q);
      while(QNext(CAdr) != QHead(*Q))
        CAdr = QNext(CAdr);
      QNext(CAdr)     = QNext(QHead(*Q));
      QNext(QHead(*Q)) = QueueNil;
      QHead(*Q) = QNext(QHead(*Q));
    }
  }
}
void QueueRotate(QueueO /* QueueOut */) {
  // Memutar antrian sirkular, sekalian menetapkan poros dari antrian tersebut
  // IS - hanya berlaku pada antrian sirkular
  // FS - antrian akan dirotasi 1x, dengan penunjuk pada poros tidak berubah
  //      elemen paling depan akan pindah ke belakang
  // KAMUS LOKAL
  QueueAddress Adr; // Temporary Address
  // ALGORITMA
  QueueDequeue(Q,&Adr);
  QueueAddAddr(Q, Adr);
}
// Other Functions
// Standard IO -- Inspect-Write-Read based

#if 0

// DICE GAME ADDITION
// definisi state player paling awal
Player firstPlayer;

int  IdxEff(QueueI) {
  // Mengembalikan banyaknya elemen pada Queue
  return NBElmt(Q);
}
bool IsGame(QueueI) {
  // Menyatakan apakah game tersebut sudah selesai atau tidak, dengan kondisi:
  // - Pemain tinggal satu
  // - Salah satu pemain mendapatkan nilai 3
  // KAMUS LOKAL
  unsigned char maxScore = 0;
  unsigned char N        = IdxEff(Q);
  Player currPlayer      = Q.T[Head(Q)];
  // ALGORITMA
  if(N<=1) { return false; }
  while(strcmp(Name(Q.T[Head(Q)]),Name(firstPlayer))==0){
    ChangeTurn(&Q);
  }
  while(N--) {
    maxScore=max(Score(Q.T[Head(Q)]),maxScore);
    ChangeTurn(&Q); // fungsi change turn disini untuk menukar elemen
  }
  while(strcmp(Name(Q.T[Head(Q)]),Name(currPlayer))==0){ChangeTurn(&Q);}
  N = IdxEff(Q);
  while(--N){ChangeTurn(&Q);}
  return (maxScore<3);
}
void CreateQueuePemain(QueueO,int max) {
  // IS - Queue kosong dengan alokasi 2-4 elemen
  // FS - Mengembalikan Q yang berisi informasi seluruh pemain berupa nama dengan
  //      skor awal 0
  // KAMUS LOKAL
  int t = max;
  InfoType X;
  // ALGORITMA
  CreateEmpty(Q,max);
  strcpy(Name(X),"");
  Score(X) = 0;
  while(t--) {
    Add(Q,X);
  }
}
void ChangeTurn(QueueO) {
  // IS - Queue paling tidak 2 elemen
  // FS - Headnya akan dilempar ke belakang Tail.
  // KAMUS LOKAL
  InfoType X;
  // ALGORITMA
  Del(Q,&X);
  Add(Q, X);
}
void ShowScore(QueueI) {
  // IS - Queue tidak kosong
  // FS - menampilkan seluruh nilai pemain sesuai dengan format yang telah ditentukan
  // KAMUS LOKAL
  unsigned char N        = IdxEff(Q);
  Player currPlayer      = Q.T[Head(Q)];
  // ALGORITMA
  while(strcmp(Name(Q.T[Head(Q)]),Name(firstPlayer))==0){ChangeTurn(&Q);}
  while(--N){ChangeTurn(&Q);}
  N = IdxEff(Q);
  while(N--) {
    printf("%10s : %i",Name(Q.T[Head(Q)]),Score(Q.T[Head(Q)]));
    ChangeTurn(&Q); // fungsi change turn disini untuk menukar elemen
  }
  while(strcmp(Name(Q.T[Head(Q)]),Name(currPlayer))==0){ChangeTurn(&Q);}
  N = IdxEff(Q);
  if(strcmp(Name(firstPlayer),Name(currPlayer))!=0){
  while(--N){ChangeTurn(&Q);}}
}

#endif
