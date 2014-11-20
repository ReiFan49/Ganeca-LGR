/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : Array_03.h
  Tangggal  : 12 November 2014
  Deskripsi : Header untuk AbstractDataType dari Array
*/

// Cek apakah suatu header sudah diload atau belum
#ifndef ReiHakurei_AbstrackDataArray
  #define ReiHakurei_AbstrackDataArray
  #include "boolean.h"
  #define IdxUndef    IdxUDF
  #define AryLInd          1
  #define IdxUDF          -1
  #define outAry   Array *A
  #define oneAry   Array  A
  #define twoAry   Array A1, Array A2
  #define inOutAry Array AI, Array*AO
  // Definisi Abstract Data Type Array
    typedef int ArrayIndexType;
    typedef int ArrayElemtType;
    typedef struct {
      ArrayElemtType *T;
      int NEff;
      int MEff; // Maximum Effective
    } Array;
    // indeks untuk pada tabel adalah dari LowInd..HighInd
  // Konstrucktor
    void CreateEmptyArray(outAry,int num);
    // I.S. - A dalam kondisi sembarang
    // F.S. - terbentuk A yang kosong dengan kapasitas HighInd-LowInd+1
  // Selecktor
    // SELECKTOR KAPASITAS
      int  ArrayNumElmt(oneAry);
      // Mengirimkan banyaknya elemen yang efektif pada tabel
      int  ArrayMaxElmt(oneAry);
      // Mengirimkan kapasitas maksimum sebuah tabel
    // SELECKTOR INDEKS
      // Prasyarat penggunaan fungsi --
      //   Tabel tidak kosong
      ArrayIndexType ArrayGetFirst(oneAry);
      // Mengembalikan indeks pertama tabel
      ArrayIndexType ArrayGetLast(oneAry);
      // Mengembalikan indeks akhir tabel
      ArrayElemtType ArrayGetElmt(oneAry,ArrayIndexType i);
      // Syarat tambahan -- i berada dalam jangkauan FirstIdx..LastIdx
      // Mengirimkan elemen tabel yang ke-i
  // Setter
    void ArrayCopy(inOutAry);
    // I.S. - AI terdefinisi
    // F.S. - isi dari AO disalin dari AI
    void ArraySetElmt(outAry,ArrayIndexType i,ArrayElemtType x);
    // I.S. - A terdefinisi
    // F.S. - Elemen A pada indeks ke-i bernilai x
    void ArraySetNEff(outAry,int Eff);
    // I.S. - A terdefinisi
    // F.S. - Nilai indeks efektif pada tabel A, menjadi Eff
    void ArrayAppend(outAry, ArrayElemtType x);
    // I.S. - A terdefinisi, jika tidak penuh
    // F.S. - Elemen terakhir A adalah x
    void ArrayInsert(outAry, ArrayElemtType x, ArrayIndexType i);
    // I.S. - A terdefinisi, jika tidak penuh, index valid
    // F.S. - Elemen ke-i pada A adalah x
    void ArrayDelete(outAry, ArrayIndexType i, ArrayElemtType*x);
    // I.S. - A terdefinisi, tidak kosong, index valid
    // F.S. - Elemen ke-i sudah keluar dari tabel.
    void ArrayDeleteElement(outAry, ArrayElemtType x);
    // I.S. - A terdefinisi, tidak kosong
    // F.S. - jika elemen X berada pada A, maka dikeluarkan dari tabel
  // Validatory Check
    bool ArrayIndexValid(oneAry,ArrayIndexType i);
    // Mengecek apakah indeks i pada tabel A ada dalam rentang atau tidak
    bool ArrayIndexEff(oneAry,ArrayIndexType i);
    // Mengecek apakah indeks i pada tabel A bukanlah sentinel
  // Condition Check
    bool ArrayEmpty(oneAry);
    // Mengecek apakah NEff = 0 atau tidak
    bool ArrayFull(oneAry);
    // Mengecek apakah NEff = MaxContain
  // Standard IO -- Inspect-Write-Read based
    void ArrayReadSize(outAry);
    // I.S. - A sembarang
    // F.S. - jumlah elemen untuk tabel A terdefinisi
    // PROSES >>
    //   akan memaksa pengguna memasukkan nilai efektif indeks yang tepat
    void ArrayReadEntry(outAry);
    // I.S. - A sembarang
    // F.S. - Tabel A terdefinisi, dengan elemen-elemennya terisi
    // PROSES >>
    //   - BacaNEff akan digunakan sebagai efisiensi fungsi terhadap driver yang
    //   diberikan
    void ArrayWriteEntry(oneAry);
    // I.S. - A apapun
    // F.S. - Menulis indeks-elemen ke layar jika tidak kosong,
    void ArrayInspect(oneAry);
    // I.S. - A apapun
    // F.S. - cetakan berupa bentuk tabel yang biasa ditemukan di bahasa-bahasa
    //        pemrogramman yang umum dijumpai, [A,B,C,...]
  // Aritmethic Operators
    Array ArrayArithPlus(twoAry);
    // Penjumlahan setiap elemen antar tabel
    Array ArrayArithMinus(twoAry);
    // Pengurangan setiap elemen antar tabel
  // Fungsi Lain
    Array ArrayJoin(twoAry);
    // Menggabungkan elemen-elemen A1 dengan A2
    Array ArrayDifference(twoAry);
    // Membuang elemen yang dimiliki oleh A2, di A1
    Array ArrayIntersect(twoAry);
    // Mencari elemen yang sama dari kedua tabel tersebut
    Array ArrayUnion(twoAry);
    // Menggabungkan kedua array, mirip seperti join.
    // Tetapi membuang elemen yang sama
#endif
