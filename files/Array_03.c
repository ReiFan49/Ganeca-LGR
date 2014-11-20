/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : Array_03.c
  Tangggal  : 12 November 2014
  Deskripsi : Body untuk AbstractDataType dari Array
*/

// Include Library yang dibutuhkan
#include <stdio.h>
#include <math.h>
#include "Array_03.h"
#include "alloc.h"

// Realisasi Abstract Data Array

// Konstrucktor
  void CreateEmptyArray(outAry,int num) {
    // I.S. - A dalam kondisi sembarang
    // F.S. - terbentuk A yang kosong dengan kapasitas HighInd-LowInd+1
    if((*A).T!=NULL)
      free((*A).T);
    (*A).T    = alloc(ArrayElemtType,num);
    (*A).NEff = 0;
  }
// Selecktor
  // SELECKTOR KAPASITAS
    int  ArrayNumElmt(oneAry) {
      // Mengirimkan banyaknya elemen yang efektif pada tabel
      return A.NEff;
    }
    int  ArrayMaxElmt(oneAry) {
      // Mengirimkan kapasitas maksimum sebuah tabel
      return A.MEff-AryLInd+1;
    }
  // SELECKTOR INDEKS
    // Prasyarat penggunaan fungsi --
    //   Tabel tidak kosong
    ArrayIndexType ArrayGetFirst(oneAry) {
      // Mengembalikan indeks pertama tabel
      return AryLInd;
    }
    ArrayIndexType ArrayGetLast(oneAry) {
      // Mengembalikan indeks akhir tabel
      return ArrayGetFirst(A)+ArrayNumElmt(A)-1;
    }
    ArrayElemtType ArrayGetElmt(oneAry,ArrayIndexType i) {
      // Syarat tambahan -- i berada dalam jangkauan FirstIdx..LastIdx
      // Mengirimkan elemen tabel yang ke-i
      return A.T[i-AryLInd];
    }
// Setter
  void ArrayCopy(inOutAry) {
    // I.S. - AI terdefinisi
    // F.S. - isi dari AO disalin dari AI
    // ** KAMUS LOKAL **
    int i;
    // **  ALGORITMA  **
    CreateEmptyArray(*AO,ArrayMaxElmt(AI));
    (*AO).NEff = AI.NEff;
    for(i=ArrayGetFirst(*AO);i<=ArrayGetLast(*AO);i++)
      (*AO).T[i-AryLInd] = AI.T[i-AryLInd];
  }
  void ArraySetElmt(outAry,ArrayIndexType i,ArrayElemtType x) {
    // I.S. - A terdefinisi
    // F.S. - Elemen A pada indeks ke-i bernilai x
    // **  ALGORITMA  **
    (ArrayIndexValid(*A,i)) ? 
      ((*A).T[i-AryLInd] = x) : 
      (printf("Indeks ke-%s tidak valid!\n",i));
  }
  void ArraySetNEff(outAry,int Eff) {
    // I.S. - A terdefinisi
    // F.S. - Nilai indeks efektif pada tabel A, menjadi Eff
    // **  ALGORITMA  **
    (Eff <= ArrayMaxElmt(*A) && Eff >= 0) ?
      (A->NEff = Eff) :
      (printf("Nilai efektif tabel tidak valid!\n"));
  }
  void ArrayAppend(outAry, ArrayElemtType x) {
    // I.S. - A terdefinisi, jika tidak penuh
    // F.S. - Elemen terakhir A adalah x
    if(!ArrayFull(*A)) {
      ArraySetElemt(A,ArrayNumElmt(*A),x)
      ArraySetNEff(A,ArrayNumElmt(*A)+1);
    } else {
      printf("Tabel penuh!\n");
    }
  }
  void ArrayInsert(outAry, ArrayElemtType x, ArrayIndexType i) {
    // I.S. - A terdefinisi, jika tidak penuh, index valid
    // F.S. - Elemen ke-i pada A adalah x
    // KAMUS LOKAL
    ArrayIndexType ind;
    // ALGORITMA
    if(!ArrayFull(*A)&&ArrayIndexEff(*A,i)){
      ArrayAppend(A,x);
      for(ind=ArrayNumElmt(*A);ind>i;i--){
        ArraySetElmt(*A, ind  ,ArrayGetElmt(*A,ind) + ArrayGetElmt(*A,ind-1));
        ArraySetElmt(*A, ind-1,ArrayGetElmt(*A,ind) - ArrayGetElmt(*A,ind-1));
        ArraySetElmt(*A, ind  ,ArrayGetElmt(*A,ind) - ArrayGetElmt(*A,ind-1));
      }
    } else {
      printf("Tabel penuh atau indeks tidak valid!\n");
    }
  }
  void ArrayDelete(outAry, ArrayIndexType i, ArrayElemtType*x){
    // I.S. - A terdefinisi, tidak kosong, index valid
    // F.S. - Elemen ke-i sudah keluar dari tabel.
    // KAMUS LOKAL
    ArrayIndexType ind;
    // ALGORITMA
    if(!ArrayEmpty(*A)&&ArrayIndexEff(*A,i)){
      x = ArrayGetElmt(*A,i);
      for(ind=i;i<ArrayNumElmt(*A);i++) {
        ArraySetElmt(*A, ind  ,ArrayGetElmt(*A,ind) + ArrayGetElmt(*A,ind+1));
        ArraySetElmt(*A, ind+1,ArrayGetElmt(*A,ind) - ArrayGetElmt(*A,ind+1));
        ArraySetElmt(*A, ind  ,ArrayGetElmt(*A,ind) - ArrayGetElmt(*A,ind+1));
      }
      ArraySetNEff(A,ArrayGetNEff(*A)-1);
    }
  }
  void ArrayDeleteElement(outAry, ArrayElemtType x){
    // I.S. - A terdefinisi, tidak kosong
    // F.S. - jika elemen X berada pada A, maka dikeluarkan dari tabel
    // KAMUS LOKAL
    ArrayIndexType ind;
    ArrayElemtType ele;
    // ALGORITMA
    if(!ArrayEmpty(*A)){
      for(ind=0;ind<ArrayNumElmt(*A);ind++)
        if(ArrayGetElmt(*A,i)==x)
          ArrayDelete(&A,ind,&ele);
    }
  }
// Validatory Check
  bool ArrayIndexValid(oneAry,ArrayIndexType i) {
    // Mengecek apakah indeks i pada tabel A ada dalam rentang atau tidak
    return (i < ArrayGetFirst(A)+ArrayMaxElmt(A) && i >= ArrayGetFirst(A));
  }
  bool ArrayIndexEff(oneAry,ArrayIndexType i) {
    // Mengecek apakah indeks i pada tabel A bukanlah sentinel
    return (i <= ArrayGetLast(A) && i >= ArrayGetFirst(A));
  }
// Condition Check
  bool ArrayEmpty(oneAry) {
    // Mengecek apakah NEff = 0 atau tidak
    return (ArrayNumElmt(A)==0);
  }
  bool ArrayFull(oneAry) {
    // Mengecek apakah NEff = MaxContain
    return (ArrayNumElmt(A)==ArrayMaxElmt(A));
  }
  bool ArrayElmtExists(oneAry,ArrayElemtType X) {
    // Mengecek apakah ada elemen X pada array tersebut
    // KAMUS LOKAL
    bool f=false;
    ArrayIndexType i;
    // ALGORITMA
    for(i=0;i<ArrayNumElmt(A)&&!f;i++)
      f|=ArrayGetElmt(A,i)==X;
    return f;
  }
// Standard IO -- Inspect-Write-Read based
  void ArrayReadSize(outAry) {
    // I.S. - A sembarang
    // F.S. - jumlah elemen untuk tabel A terdefinisi
    // PROSES >>
    //   akan memaksa pengguna memasukkan nilai efektif indeks yang tepat
    // ** KAMUS LOKAL **
    int n;
    // **  ALGORITMA  **
    (*A).NEff = -1;
    for(;ArrayNumElmt(*A)<0;){
      printf("Jumlah elemen tabel : ");
      scanf("%i",&n);
      ArraySetNEff(A,n);
    }
  }
  void ArrayReadEntry(outAry)  {
    // I.S. - A sembarang
    // F.S. - Tabel A terdefinisi, dengan elemen-elemennya terisi
    // PROSES >>
    //   - BacaNEff akan digunakan sebagai efisiensi fungsi terhadap driver yang
    //   diberikan
    // ** KAMUS LOKAL **
    ArrayIndexType   i;
    ArrayElemtType x;
    // **  ALGORITMA  **
    for(i=ArrayGetFirst(*A);i<=ArrayGetLast(*A);i++) {
      printf("Isi indeks ke-%i : ",i);
      scanf("%i",&x);
      ArraySetElemt(A,i,x);
    }
  }
  void ArrayWriteEntry(oneAry){
    // I.S. - A apapun
    // F.S. - Menulis indeks-elemen ke layar jika tidak kosong,
    // ** KAMUS LOKAL **
    ArrayIndexType   i;
    // **  ALGORITMA  **
    for(i=ArrayGetFirst(A);i<=ArrayGetLast(A);i++) {
      if(i>ArrayMaxElmt(A)){break;}
      printf("Isi indeks ke-%i : %i\n",i,ArrayGetElemt(A,i));
    }
  }
  void ArrayInspect(oneAry) {
    // I.S. - A apapun
    // F.S. - cetakan berupa bentuk tabel yang biasa ditemukan di bahasa-bahasa
    //        pemrogramman yang umum dijumpai, [A,B,C,...]
    // ** KAMUS LOKAL **
    ArrayIndexType   i;
    // **  ALGORITMA  **
    printf("[");
    for(i=ArrayGetFirst(A);i<=ArrayGetLast(A);i++) {
      printf("%i%s",ArrayGetElemt(A,i),(i < ArrayGetLast(A))?(", "):(""));
    }
    printf("]");
  }
// Aritmethic Operators
  Array ArrayArithPlus(twoAry) {
    // Penjumlahan setiap elemen antar tabel
    // ** KAMUS LOKAL **
    Array AS;
    ArrayIndexType   i;
    // **  ALGORITMA  **
    ArrayCopy(A1,&AS);
    for(i=ArrayGetFirst(A1);i<=ArrayGetLast(A1);i++)
      ArraySetElemt(&AS,i,ArrayGetElemt(A1,i)+ArrayGetElemt(A2,i));
    return AS;
  }
  Array ArrayArithMinus(twoAry) {
    // Pengurangan setiap elemen antar tabel
    // ** KAMUS LOKAL **
    Array AS;
    ArrayIndexType   i;
    // **  ALGORITMA  **
    ArrayCopy(A1,&AS);
    for(i=ArrayGetFirst(A1);i<=ArrayGetLast(A1);i++)
      ArraySetElemt(&AS,i,ArrayGetElemt(A1,i)-ArrayGetElemt(A2,i));
    return AS;
  }
// Fungsi Lain
  Array ArrayJoin(twoAry) {
    // Menggabungkan elemen-elemen A1 dengan A2
    // KAMUS LOKAL
    Array AS;
    ArrayIndexType i;
    // ALGORITMA
    CreateEmptyArray(&AS,ArrayNumElmt(A1)+ArrayNumElmt(A2));
    for(i=ArrayGetFirst(A1);i<=ArrayGetLast(A1);i++)
      ArrayAppend(&AS,ArrayGetElmt(A1,i));
    for(i=ArrayGetFirst(A2);i<=ArrayGetLast(A2);i++)
      ArrayAppend(&AS,ArrayGetElmt(A2,i));
    return AS;
  }
  Array ArrayDifference(twoAry) {
    // Membuang elemen yang dimiliki oleh A2, di A1
    // KAMUS LOKAL
    Array AS,AD;
    ArrayIndexType i;
    // ALGORITMA
    CreateEmptyArray(&AS,ArrayNumElmt(A1));
    ArrayCopy(A1,&AS);
    AD = ArrayIntersect(A1,A2);
    for(i=0;i<ArrayNumElmt(AD);i++)
      ArrayDeleteElement(&AS,ArrayGetElmt(AD,i));
    free(AD.T);
    return AS;
  }
  Array ArrayIntersect(twoAry) {
    // Mencari elemen yang sama dari kedua tabel tersebut
    // KAMUS LOKAL
    Array AS;
    ArrayIndexType i,j;
    // ALGORITMA
    CreateEmptyArray(&AS,(ArrayNumElmt(A1)>ArrayNumElmt(A2))?ArrayNumElmt(A1):ArrayNumElmt(A2));
    for(i=ArrayGetFirst(A1);i<=ArrayGetLast(A1);i++)
      for(j=ArrayGetFirst(A2);j<=ArrayGetLast(A2)&&
                                !ArrayElmtExists(AS,ArrayGetElmt(A1));j++)
        if(ArrayGetElmt(A1,i)==ArrayGetElmt(A2,i)&&
           !ArrayElmtExists(AS,ArrayGetElmt(A1)))
          ArrayAppend(&AS,ArrayGetElmt(A1))
    return AS;
  }
  Array ArrayUnion(twoAry) {
    // Menggabungkan kedua array, mirip seperti join.
    // Tetapi membuang elemen yang sama
    // KAMUS LOKAL
    Array AS,AU;
    ArrayIndexType i;
    // ALGORITMA
    AU = ArrayIntersect(A1,A2);
    AS = ArrayJoin(ArrayDifference(ArrayJoin(A1,A2),AU),AU);
    free(AU.T);
    return AS;
  }
