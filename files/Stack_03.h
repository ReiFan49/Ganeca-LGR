/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : Stack_03.h
  Tangggal  : 12 November 2014
  Deskripsi : Header untuk AbstractDataType dari Stack (Representasi: Tabel)
*/

#ifndef ReiHakurei_ArrayStack
  #define ReiHakurei_ArrayStack
  // Library bawaan
  #include  "boolean.h"
  #include  "ADTTypeDef.h"
  // Deklarasi Konstanta
  #define   StackNil  0
  #define   STop(S)  (S).TOP
  #define   SMax(S)  (S).Max
  #define   SInfo(S) (S).T[(S).TOP]
  #define   StackI    Stack S
  #define   StackO    Stack*S
  #define   StElWI    StackO,StackInfoType X
  #define   StElWO    StackO,StackInfoType*X 
  
  // Definisi Abstract Data Type Stack (Representasi: Tabel)
  #ifdef StackData
  typedef StackData StackInfoType; 
  #else
  #pragma warning 'Type of Stack Element -> default (int)'
  typedef int       StackInfoType;
  #endif
  #undef MatrData
  #undef QueueData
  #undef StackData
  #undef LLData
  typedef int       StackAddress;
  typedef struct {
    StackInfoType*T;
    StackAddress  TOP;
    int           Max;
  } Stack;
  // Konstrucktor
    void CreateEmptyStack (StackO, int max);
    // IS - Stack sembarang
    // FS - Membuat Stack yang kosong berkapasitas MaxEl
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
    bool StackIsEmpty(StackI);
    // Mengecek apakah TOP dari Stack tersebut adalah nil
    bool StackIsFull (StackI);
    // Mengecek apakah TOP dari Stack tersebut sudah menyentuk MaxEl atau tidak
  // Basic Functions
    void StackPush(StElWI);
    // Menambahkan elemen X pada puncak Stack S
    // IS - S mungkin kosong, asalkan tidak penuh
    // FS - X adalah Top Stack yang baru, dengan arahan Top naik  1
    void StackPop (StElWO);
    // Menambahkan elemen X pada puncak Stack S
    // IS - S harus terisi
    // FS - X adalah Top Stack yang lama, dengan arahan Top turun 1
  // Other Functions
  // Standard IO -- Inspect-Write-Read based
    void StackWrite(StackI);
    // Mencetak semua elemen dari stack tersebut
    // IS - S dalam kondisi apapun
    // FS - semua elemen dari stack tersebut tercetak
  
#endif
