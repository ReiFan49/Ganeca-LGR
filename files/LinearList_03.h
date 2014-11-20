/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : LinearList_03.h
  Tangggal  : 12 November 2014
  Deskripsi : Header untuk ADT LinearList
*/

#ifndef ReiHakurei_List
  #define ReiHakurei_List
  // Library bawaan
  #include  "boolean.h"
  #include  "ADTTypeDef.h"
  // Deklarasi Konstanta dan Makro
  #define   LLNil       NULL
  #define   LLFirst(LL) (LL).First
  #define   LLNext(Adr) (Adr)->succ
  #define   LLInfo(Adr) (Adr)->val
  #define   LLAddrI     LLAddress  Adr
  #define   LLAddrB4    LLAddress PAdr
  #define   LLAddrO     LLAddress* Adr
  #define   LLElmtI     LLInfoType X
  #define   LLElmtO     LLInfoType*X
  #define   LListI      LList LL
  #define   LListO      LList*LL

  // Definisi Abstract Data Type Mahasiswa
  #ifdef  LLData
    typedef LLData LLInfoType; // to define this, it should be defined before
  #else
    #pragma warning "Type of Linked-List Element -> default (int)"
    typedef int    LLInfoType; // to define this, it should be defined before
  #endif
  #undef MatrData
  #undef QueueData
  #undef StackData
  #undef LLData
  typedef struct tLLElmt* LLAddress;
  typedef struct tLLElmt {
    LLInfoType val;
    LLAddress  succ;
  } LLElmt;
  typedef struct tLLHead {
    LLAddress  First;
  } LLHead;
  typedef LLHead LList;
  // Memory Management
    LLAddress LLElemtAlloc (LLElmtI);
    // Mengirimkan address mahasiswa hasil alokasi elemen
    // Jika alokasi berhasil, maka Info(P) adalah X, dan Suksesornya tidak ada,
    //      selain itu, maka akan dikembalikan nil
    void LLElemtDealloc (LLAddrO);
    // IS - Adr sedang dialokasi
    // FS - Adr menjadi tidak terdefinisi, dikembalikan ke sistem
  // Konstrucktor
    void CreateEmptyList(LListO);
    // IS - List sembarang
    // FS - Membuat List yang kosong
  // Destructor
  // Predicate Functions
    bool LLIsEmpty(LListI);
      // mengecek apakah list tersebut kosong atau tidak
  // Iterator
    LLAddress LLSearchData(LListI,LLElmtI);
    // mencari apakah ada elemen dalam list tersebut,
    // jika berhasil, akan dikembalikan LLAddress terhadap elemen tersebut
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
    void LLInsertFirst(LListO, LLAddrI);
    // IS - Adr teralokasi
    // FS - Adr sebagai elemen pertama yang baru pada list tersebut
    void LLInsertAfter(LListO, LLAddrI, LLAddrB4);
    // IS - Adr teralokasi + Pred bukan elemen terakhir
    // FS - Adr sebagai elemen sesudah elemen beralamat Pred
    void LLInsertFinal(LListO, LLAddrI);
    // IS - Adr teralokasi
    // FS - Adr sebagai elemen terakhir yang baru dari list tersebut
    void LLDeleteValue(LListO, LLElmtI);
    // IS - L tidak kosong
    // FS - Jika ada elemen list yang beralamat Adr, maka
    //      Elemen list berkurang satu
  // Other Functions
  // Standard IO -- Inspect-Write-Read based
    void LLWriteEntry(LListI) ;
    // IS - L terdefinisi
    // FS - semua elemen dalam list dicetak kelayar

#endif
