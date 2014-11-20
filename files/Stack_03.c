/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : Stack_03.c
  Tangggal  : 12 November 2014
  Deskripsi : Body untuk AbstractDataType dari Stack (Representasi: Tabel)
*/

// Library bawaan
#include "boolean.h"
#include <stdio.h>
#include "alloc.h"
#include <string.h>
#include "Stack_03.h"

// Definisi Abstract Data Type Stack (Representasi: Kontigu)
// Konstrucktor
void CreateEmptyStack (StackO, int max) {
  // IS - Stack sembarang
  // FS - Membuat Stack yang kosong berkapasitas MaxEl
  if(S->T != NULL) {
    printf("Stack sebelumnya, belum dialokasi!\n");
  }
  S->T = alloc(StackInfoType,max+1);
  SMax(*S) = (S->T != NULL) ? max : StackNil;
  STop(*S) = StackNil;
  if(S->T == NULL) {
    printf("Stack gagal dialokasi!\n");
  }
}
// Destructor
void StackDealokasi (StackO) {
  // IS - S sedang dialokasi
  // FS - S menjadi tidak terdefinisi, dengan MaxEl adalah 0
  free(S->T);
  S->T = NULL;
  SMax(*S) = STop(*S) = StackNil;
}
// Validatory Check
// Selecktor
  // SELECKTOR KAPASITAS
  // SELECKTOR INDEKS
  // SELECKTOR ALIASES
// Setter
  // SETTER DEFINITION
  // SETTER ALIASES
// Aritmethic Operators
// Comparable Operators
// Predicate Functions
  bool StackIsEmpty(StackI) {
    // Mengecek apakah TOP dari Stack tersebut adalah nil
    return (STop(S) == StackNil);
  }
  bool StackIsFull (StackI) {
    // Mengecek apakah TOP dari Stack tersebut sudah menyentuk MaxEl atau tidak
    return (STop(S) > SMax(S));
  }
// Basic Functions
  void StackPush   (StElWI) {
    // Menambahkan elemen X pada puncak Stack S
    // IS - S mungkin kosong, asalkan tidak penuh
    // FS - X adalah Top Stack yang baru, dengan arahan Top naik  1
    // ALGORITMA
    if(StackIsFull(*S)){
      printf("Stack penuh\n");
    } else {
      STop(*S) ++;
      SInfo(*S)=X;
    }
  }
  void StackPop    (StElWO) {
    // Menambahkan elemen X pada puncak Stack S
    // IS - S harus terisi
    // FS - X adalah Top Stack yang lama, dengan arahan Top turun 1
    // ALGORITMA
    if(StackIsEmpty(*S)){
      printf("Stack kosong\n");
    } else {
      *X=SInfo(*S);
      STop(*S)  --;
    }
  }
// Other Functions
// Standard IO -- Inspect-Write-Read based
  void StackWrite(StackI) {
    // Mencetak semua elemen dari stack tersebut
    // IS - S dalam kondisi apapun
    // FS - semua elemen dari stack tersebut tercetak
    // KAMUS LOKAL
      Stack         ST;
      StackInfoType X ;
      int           i ;
    // ALGORITMA
      CreateEmptyStack(&ST,SMax(S));
      printf("Elemen Stack : ");
      if(!StackIsEmpty(S)){
        while(!StackIsEmpty(S)) {
          StackPop(&S,&X); StackPush(&ST,X);}
        while(!StackIsEmpty(ST)){
          StackPop(&ST,&X); StackPush(&S,X);
          printf("%i%s",X,(StackIsEmpty(ST))?("\n"):(","));
        }
      } else { printf("<kosong>\n"); }
    // END OF SUBPROGRAM
  }
