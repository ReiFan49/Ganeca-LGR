/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : Queue_03.c
  Tangggal  : 12 November 2014
  Deskripsi : Header untuk ADT Queue (Representasi: List Sirkular)
*/

#ifndef ReiHakurei_ListCircQueue
  #define ReiHakurei_ListCircQueue
  // Library bawaan
  #include  "boolean.h"
  #include  "ADTTypeDef.h"
  // Deklarasi Konstanta dan Makro
  #define   QueueNil        NULL
  #define   QHead(Q)    (Q).head
  #define   QTail(Q)    (Q).head
  #define   QInfo(Adr)  (Adr)->data
  #define   QNext(Adr)  (Adr)->succ
  #define   QIndex(Adr) (Adr)->index
  #define   QueueI       Queue Q
  #define   QueueO       Queue*Q
  #define   QwElmI       QueueInfoType X
  #define   QwElmO       QueueInfoType*X
  #define   QwAdrI       QueueAddress  Adr
  #define   QwAdrO       QueueAddress *Adr
  
  // Definisi Abstract Data Type Queue
  #ifdef  QueueData
    typedef QueueData QueueInfoType; // to define this, it should be defined before
  #else
    #pragma GCC warning "Type of Queue Element -> default (int)"
    typedef int QueueInfoType; // to define this, it should be defined before
  #endif
  typedef struct tQElmt* QueueAddress ;
  typedef struct tQElmt  {
    QueueInfoType data;
    QueueAddress  succ;
    int           index;   // Untuk melacak indeks dari antrian sirkular
  } QueueElement;
  typedef struct {
    QueueAddress  head;
  } Queue;
  #undef MatrData
  #undef QueueData
  #undef StackData
  #undef LLData
  // Konstruktor
    void CreateEmptyQueue (QueueO /* output: Queue */);
    // IS - Queue sembarang
    // FS - Membuat Antrian Sirkular dengan kapasitas tak terbatas
    //      dalam kondisi kosong
  // Destructor
    void QueueDealokasi (QueueO /* output: Queue (self) */);
    // IS - Q sedang dialokasi
    // FS - Q menjadi tidak terdefinisi, dengan MaxEl adalah 0
  // Memory Management
    QueueAddress QueueElemtAllocate(QueueI,QwElmI);
    // mengalokasikan elemen X kedalam memori
    // jika gagal maka dikembalikan nil.
    void QueueElemtDealloc(QwAdrO);
    // melepaskan Adr ke memori,
  // Validatory Check
  // Selecktor
    // SELECKTOR KAPASITAS
    int  QueueCount  (QueueI /* Single Queue */);
    // Mengirimkan banyaknya elemen di queue
    // SELECKTOR INDEKS
    // SELECKTOR ALIASES
  // Setter
    // SETTER DEFINITION
    // SETTER ALIASES
  // Aritmethic Operators
  // Comparable Operators
  // Predicate Functions
    bool QueueIsEmpty(QueueI /* Single Queue */);
    // Mengecek apakah Head-Tail dari Queue tersebut adalah nil
    bool QueueIsAlone(QueueI /* Single Queue */);
    // Mengecek apakah Queue tersebut adalah antrian yang sendirian
    bool QueueIsFull (QueueI /* Single Queue */);
    // Mengecek apakah Tail dari Queue tersebut sudah menyentuh MaxEl atau tidak
  // Basic Functions
    void QueueAddElmt(QueueO,QwElmI /* QueueOut-SingleElement */);
    // Menambahkan elemen X pada Queue Q paling belakang
    // IS - Q tidak penuh
    // FS - X adalah Tail yang baru, dengan arahan Tail berubah
    void QueueAddAddr(QueueO,QwAdrI /* QueueOut-SingleAddress */);
    // Menyisipkan address Adr pada Queue Q paling belakang
    // IS - Q tidak penuh, dan head,adr terdefinisi
    // FS - Adr adalah alamat yang baru.
    void QueueDequeue(QueueO,QwAdrO /* QueueOut-ReturnAddress */);
    // Membuang elemen pertama pada Q, dengan aturan FIFO
    // IS - Q harus terisi
    // FS - Adr adalah alamat kepada elemen pertama pada queue,
    //      Next dari Adr akan dimatikan menjadi nil.
  // Other Functions
  // Standard IO -- Inspect-Write-Read based
#endif

//#ifndef ReiHakurei_DiceGame
#if 0
  #define ReiHakurei_DiceGame

  int  IdxEff(QueueI);
  // Mengembalikan banyaknya elemen pada Queue
  bool IsGame(QueueI);
  // Menyatakan apakah game tersebut sudah selesai atau tidak, dengan kondisi:
  // - Pemain tinggal satu
  // - Salah satu pemain mendapatkan nilai 3
  void CreateQueuePemain(QueueO,int max);
  // IS - Queue kosong dengan alokasi 2-4 elemen
  // FS - Mengembalikan Q yang berisi informasi seluruh pemain berupa nama dengan
  //      skor awal 0
  void ChangeTurn(QueueO);
  // IS - Queue paling tidak 2 elemen
  // FS - Headnya akan dilempar ke belakang Tail.
  void ShowScore(QueueI);
  // IS - Queue tidak kosong
  // FS - menampilkan seluruh nilai pemain sesuai dengan format yang telah ditentukan
  
#endif
