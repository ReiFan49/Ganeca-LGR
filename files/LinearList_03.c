/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : LinearList_03.c
  Tangggal  : 12 November 2014
  Deskripsi : Body untuk ADT LinearList
*/

// Library bawaan
#include "boolean.h"
#include <stdio.h>
#include "alloc.h"
#include <string.h>
#include "LinearList_03.h"

// Definisi Abstract Data Type List Linear
// Memory Management
LLAddress LLElemtAlloc  (LLElmtI) {
  // Mengirimkan address mahasiswa hasil alokasi elemen
  // Jika alokasi berhasil, maka Info(P) adalah X, dan Suksesornya tidak ada,
  //      selain itu, maka akan dikembalikan nil
  // KAMUS LOKAL
  LLAddress Adr;
  // ALGORITMA
  Adr = alloc(LLElmt,1);
  if(Adr != LLNil) {
    LLInfo(Adr) = X;
    LLNext(Adr) = LLNil;
  }
  // END OF SUBPROGRAM
  return Adr;
}
void LLElemtDealloc   (LLAddrO) {
  // IS - Adr sedang dialokasi
  // FS - Adr menjadi tidak terdefinisi, dikembalikan ke sistem
  free(*Adr);
  *Adr = LLNil;
}
// Konstrucktor
void CreateEmptyList  (LListO) {
  // IS - List sembarang
  // FS - Membuat List yang kosong
  LL->First = LLNil;
}
// Destructor
// Predicate Functions
bool LLIsEmpty(LListI) {
    // mengecek apakah list tersebut kosong atau tidak
  return LLFirst(LL)==LLNil;
}
// Iterator
LLAddress LLSearchData(LListI,LLElmtI) {
  // mencari apakah ada elemen dalam list tersebut,
  // jika berhasil, akan dikembalikan LLAddress terhadap elemen tersebut
  // KAMUS LOKAL
  LLAddress CAdr;
  // ALGORITMA
  CAdr = LLFirst(LL);
  if (!LLIsEmpty(LL)) {
    while((CAdr!=LLNil)?(LLInfo(CAdr)==X):(false)) {
      CAdr = LLNext(CAdr);
    }
  } else {
    return LLNil;
  }
  // END OF SUBPROGRAM
  return CAdr;
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
// Basic Functions
void LLInsertFirst(LListO, LLAddrI) {
  // IS - Adr teralokasi
  // FS - Adr sebagai elemen pertama yang baru pada list tersebut
  // KAMUS LOKAL
  LLAddress EAdr;
  // ALGORITMA
  EAdr = LLFirst(*LL);
  LLFirst(*LL) = Adr;
  LLNext(Adr)  = EAdr;
}
void LLInsertAfter(LListO, LLAddrI, LLAddrB4) {
  // IS - Adr teralokasi + Pred bukan elemen terakhir
  // FS - Adr sebagai elemen sesudah elemen beralamat Pred
  // KAMUS LOKAL
  // ALGORITMA
  LLNext(Adr)   = LLNext(PAdr);
  LLNext(PAdr)  = Adr;
}
void LLInsertFinal(LListO, LLAddrI) {
  // IS - Adr teralokasi
  // FS - Adr sebagai elemen terakhir yang baru dari list tersebut
  // KAMUS LOKAL
  LLAddress CAdr;
  // ALGORITMA
  CAdr = LLFirst(*LL);
  if(!LLIsEmpty(*LL)){
    while(LLNext(CAdr)!=LLNil)
      CAdr = LLNext(CAdr);
    LLNext(CAdr) = Adr;
  } else 
    LLInsertFirst(LL,Adr);
}
void LLDeleteValue(LListO, LLElmtI) {
  // IS - L tidak kosong
  // FS - Jika ada elemen list yang beralamat Adr, maka
  //      Elemen list berkurang satu
  // KAMUS LOKAL
  LLAddress EAdr,CAdr,PAdr;
  // ALGORITMA
  CAdr = LLFirst(*LL);
  EAdr = LLSearchData(*LL,X);
  if(EAdr!=LLNil){
    if(CAdr==EAdr){
      LLFirst(*LL) = LLNext(CAdr);
    }else{
      while((CAdr!=LLNil)?(LLNext(CAdr)!=EAdr):(false)) {
        CAdr = LLNext(CAdr); }
      if(CAdr==LLNil){
      }else{
        LLNext(CAdr)= LLNext(EAdr);
        LLNext(EAdr)= LLNil;
      }
    }
    if(CAdr!=LLNil) {
      LLElemtDealloc(&EAdr);
    }
  }
}
// Other Functions
// Standard IO -- Inspect-Write-Read based
void LLWriteEntry(LListI) {
  // IS - L terdefinisi
  // FS - semua elemen dalam list dicetak kelayar
  // KAMUS LOKAL
  LLAddress  CAdr;
  LLInfoType X;
  // ALGORITMA
  CAdr = LLFirst(LL);
  if(!LLIsEmpty(LL)){
    while(CAdr!=LLNil){
      X = LLInfo(CAdr);
      CAdr = LLNext(CAdr);
      printf("%c",10);
    }
  } else printf("list kosong%c",0x0A);
}
