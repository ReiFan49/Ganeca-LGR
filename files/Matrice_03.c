/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : Matrice_03.c
  Tangggal  : 12 November 2014
  Deskripsi : Body untuk AbstractDataType dari Matrix
*/

// Include Library yang dibutuhkan
#include <stdio.h>
#include <math.h>
#include "alloc.h"
#include "Matrice_03.h"

// Realisasi Abstract Data Matrix

// Konstrucktor
  void CreateEmptyMatrix(outMtx,rowNCol) {
    // I.S. - R x C adalah valid untuk memori matriks yang ingin dibuat
    // F.S. - terbentuk M yang kosong dengan ukuran R x C
    //        pada "ujung kiri" memori
    (*M).T = alloc(MatrElemtType,R*C);
    (*M).R = M->RM = R;
    (*M).C = M->CM = C;
  }
// Validatory Check
  bool MatrIndexValid(rowNCol) {
    // memberikan true jika R,C adalah indeks yang valid
    return (R >= 1 && R <= 5) && (C >= 1 && C <= 5);
  }
// Selecktor
  // SELECKTOR KAPASITAS
    int  MatrRowSize(oneMtx) {
      // Mengirimkan banyaknya baris yang efektif pada sebuah matriks
      return M.R;
    }
    int  MatrColSize(oneMtx) {
      // Mengirimkan banyaknya kolom yang efektif pada sebuah matriks
      return M.C;
    }
  // SELECKTOR INDEKS
    // Prasyarat penggunaan fungsi --
    //   Matriks terdefinisi
    MatrIndexType MatrFirstRow(oneMtx) {
      // Mengembalikan baris pertama matriks
      return 1;
    }
    MatrIndexType MatrFinalRow(oneMtx) {
      // Mengembalikan baris terakhir matriks
      return MatrRowSize(M);
    }
    MatrIndexType MatrFirstCol(oneMtx) {
      // Mengembalikan kolom pertama matriks
      return 1;
    }
    MatrIndexType MatrFinalCol(oneMtx) {
      // Mengembalikan kolom terakhir matriks
      return MatrColSize(M);
    }
    MatrElemtType MatrGetElemt(oneMtx,rowNCol) {
      // Syarat tambahan -- r,c adalah indeks yang valid
      // Mengirimkan elemen matriks pada r,c
      return Matr(M,R-1,C-1);
    }
// Setter
  void MatrSetRow(outMtx,int rs) {
    // I.S. - M terdefinisi
    // F.S. - Nilai baris efektif diisi dengan RS (Row-Size)
    (*M).R = rs;
  }
  void MatrSetCol(outMtx,int cs) {
    // I.S. - M terdefinisi
    // F.S. - Nilai kolom efektif diisi dengan CS (Col-Size)
    (*M).C = cs;
  }
  void MatrSetElemt(outMtx,rowNCol,MatrElemtType val) {
    // I.S. - M terdefinisi
    // F.S. - Elemen M pada r,c bernilai val
    (MatrIndexValid(R,C)) ?
      (Matr(*M,R-1,C-1) = val) :
      (printf("Invalid row-column reference\n"));
  }
// Standard IO -- Inspect-Write-Read based
  void MatrRead(outMtx) {
    // I.S. IsIdxValid(R,C)
    // F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK
    //      Melakukan MakeMatriks(M,R,C) dan mengisi nilai efektifnya
    //      dari pembacaan dengan traversal per baris
    // KAMUS LOKAL
    int i,j,r,c,v;
    // ALGORITMA
    while(!MatrIndexValid(r,c)) {
      printf("Ukuran baris      : ");scanf("%i",&r);
      printf("Ukuran kolom      : ");scanf("%i",&c);
    }
    CreateEmptyMatrix(M,r,c);
    for(i=MatrFirstRow(*M);i<=MatrFinalCol(*M);i++) {
      for(j=MatrFirstCol(*M);j<=MatrFinalCol(*M);j++) {
        printf("Isi matriks ke-(%i,%i) : ",i,j); scanf("%i",&v);
        MatrSetElemt(M,i,j,v);
    }}
  }
  void MatrWrite(oneMtx) {
    // I.S. - M apapun
    // F.S. - Menulis elemen matriks secara bentuk matriks itu sendiri
    //        (menjalar per baris)
    // KAMUS LOKAL
    int i,j,mx,md;
    char strf[7];
    // ALGORITMA
    mx = MatrGetElemt(M,MatrFirstRow(M),MatrFirstCol(M));
    for(i=MatrFirstRow(M);i<=MatrFinalRow(M);i++)
      for(j=MatrFirstCol(M);j<=MatrFinalRow(M);j++)
        mx = (mx < abs(MatrGetElemt(M,i,j))) ? abs(MatrGetElemt(M,i,j)) : (mx);
    md = ceil(log10(mx))+1;
    sprintf(strf,"%%s%%%ii%%c",md);
    for(i=MatrFirstRow(M);i<=MatrFinalRow(M);i++)
      for(j=MatrFirstCol(M);j<=MatrFinalRow(M);j++)
        printf(strf,(j==MatrFirstCol(M))?" ":"",MatrGetElemt(M,i,j),(j<MatrFinalCol(M))?(0x20):(0x0A));
  }
// Aritmethic Operators
  Matrix MatrDotProd(twoMtx) {
    // Mengkalikan M1 dengan M2, dengan cara biasa.
    // syarat => M2.RowEff == M1.ColEff 
    // hasil  => M2.RowEff x  M1.ColEff
    // KAMUS LOKAL
    Matrix M3;
    int i,j,k;
    // ALGORITMA
    CreateEmptyMatrix(&M3,MatrRowSize(M1),MatrColSize(M2));
    for(i=MatrFirstRow(M1);i<=MatrFinalRow(M1);i++)
      for(j=MatrFirstCol(M2);j<=MatrFinalCol(M2);j++) {
        MatrSetElemt(&M3,i,j,0);
        for(k=MatrFirstRow(M1);k<=MatrFinalRow(M1);k++)
          MatrSetElemt(&M3,i,j,MatrGetElemt(M3,i,j)+MatrGetElemt(M1,i,k)*MatrGetElemt(M2,k,j));
      };
    return M3;
  }
// Comparable Operators
  bool MatrIsEqual(twoMtx) {
    // mengecek apakah kedua matriks tersebut identik (dari ukuran dan elemen)
    // KAMUS LOKAL
    int i,j;
    bool  f=false;
    // ALGORITMA
    if ( MatrRowSize(M1)==MatrRowSize(M2) && MatrColSize(M1)==MatrColSize(M2) ) {
      for(i=MatrFirstRow(M1);i<=MatrFinalRow(M1)&&!f;i++)
        for(j=MatrFirstCol(M2);j<=MatrFinalCol(M2)&&!f;j++)
          f |= MatrGetElemt(M1,i,j)!=MatrGetElemt(M2,i,j) ;
      return !f;
    } else
      return false;
  }
// Fungsi Lain
  bool MatrIsIdentity(oneMtx) {
    // mengecek apakah matrix berukuran NxN ,
    //   lalu mengecek apakah matrix tersebut diagonalnya 1 dan lainnya 0,
    // bila keduanya iya, maka true
    // KAMUS LOKAL
    int  i, j;
    bool fail=false;
    // ALGORITMA
    fail |= MatrRowSize(M)==MatrColSize(M);
    for(i=MatrFirstRow(M);i<=MatrFinalRow(M)&&!fail;i++)
      for(j=MatrFirstCol(M);j<=MatrFinalCol(M)&&!fail;j++)
        fail |= MatrGetElemt(M,i,j) != ((i==j) ? 1 : 0);
    return !fail;
  }
