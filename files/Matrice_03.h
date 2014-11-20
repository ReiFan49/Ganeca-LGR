/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : Matrice_03.c
  Tangggal  : 12 November 2014
  Deskripsi : Head untuk AbstractDataType dari Matrix
*/

// Cek apakah suatu header sudah diload atau belum
#ifndef ReiHakurei_AbstrackDataMatrix
  #define ReiHakurei_AbstrackDataMatrix
  #include "boolean.h"
  #include  "ADTTypeDef.h"
  #define MIdxTp   MatrIndexType
  #define Matrices    Matrix
  #define Matr(M,R,C)    (M).T[(R)*(M).R + (C)]
  #define outMtx   Matrix *M
  #define oneMtx   Matrix  M
  #define twoMtx   Matrix M1, Matrix M2
  #define rowNCol  MIdxTp R, MIdxTp C
  // Definisi Abstract Data Type Matrix
    typedef int MatrIndexType;
    #ifdef MatrData
    typedef MatrData MatrElemtType;
    #else
    #pragma warning 'Type of Matrix Element -> default (int)'
    typedef int      MatrElemtType;
    #endif
    #undef MatrData
    #undef QueueData
    #undef StackData
    #undef LLData
    typedef struct {
      MatrElemtType *T;
      int R;  int C;  // adjustable size
      int RM; int CM; // create only base
    } Matrix;
    // indeks untuk pada matriks adalah dari R[RMin..RMax] x C[CMin..CMax]
  // Konstrucktor
    void CreateEmptyMatrix(outMtx,rowNCol);
    // I.S. - R x C adalah valid untuk memori matriks yang ingin dibuat
    // F.S. - terbentuk M yang kosong dengan ukuran R x C
    //        pada "ujung kiri" memori
  // Validatory Check
    bool MatrIndexValid(rowNCol);
    // memberikan true jika R,C adalah indeks yang valid
  // Selecktor
    // SELECKTOR KAPASITAS
      int  MatrRowSize(oneMtx);
      // Mengirimkan banyaknya baris yang efektif pada sebuah matriks
      int  MatrColSize(oneMtx);
      // Mengirimkan banyaknya kolom yang efektif pada sebuah matriks
    // SELECKTOR INDEKS
      // Prasyarat penggunaan fungsi --
      //   Matriks terdefinisi
      MatrIndexType MatrFirstRow(oneMtx);
      // Mengembalikan baris pertama matriks
      MatrIndexType MatrFinalRow(oneMtx);
      // Mengembalikan baris terakhir matriks
      MatrIndexType MatrFirstCol(oneMtx);
      // Mengembalikan kolom pertama matriks
      MatrIndexType MatrFinalCol(oneMtx);
      // Mengembalikan kolom terakhir matriks
      MatrElemtType MatrGetElemt(oneMtx,rowNCol);
      // Syarat tambahan -- r,c adalah indeks yang valid
      // Mengirimkan elemen matriks pada r,c
  // Setter
    void MatrSetRow(outMtx,int rs);
    // I.S. - M terdefinisi
    // F.S. - Nilai baris efektif diisi dengan RS (Row-Size)
    void MatrSetCol(outMtx,int cs);
    // I.S. - M terdefinisi
    // F.S. - Nilai kolom efektif diisi dengan CS (Col-Size)
    void MatrSetElemt(outMtx,rowNCol,MatrElemtType val);
    // I.S. - M terdefinisi
    // F.S. - Elemen M pada r,c bernilai val
  // Standard IO -- Inspect-Write-Read based
    void MatrRead(outMtx);
    // I.S. IsIdxValid(R,C)
    // F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK
    //      Melakukan MakeMatriks(M,R,C) dan mengisi nilai efektifnya
    //      dari pembacaan dengan traversal per baris
    void MatrWrite(oneMtx);
    // I.S. - M apapun
    // F.S. - Menulis elemen matriks secara bentuk matriks itu sendiri
    //        (menjalar per baris)
  // Aritmethic Operators
    Matrix MatrDotProd(twoMtx);
    // Mengkalikan M1 dengan M2, dengan cara biasa.
    // syarat => M2.RowEff == M1.ColEff 
    // hasil  => M2.RowEff x  M1.ColEff
  // Comparable Operators
    bool MatrIsEqual(twoMtx);
    // mengecek apakah kedua matriks tersebut identik (dari ukuran dan elemen)
  // Fungsi Lain
    bool MatrIsIdentity(oneMtx);
    // mengecek apakah matrix berukuran NxN ,
    //   lalu mengecek apakah matrix tersebut diagonalnya 1 dan lainnya 0,
    // bila keduanya iya, maka true
#endif
