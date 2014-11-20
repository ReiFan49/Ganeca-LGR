/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : alloc.h
  Tangggal  : 12 November 2014
  Deskripsi : Sebagai pembantu alokasi
*/

#ifndef ReiHakurei_Allocate
#define ReiHakurei_Allocate
  // Inklusi library tambahan
  #include <stdlib.h>
  // Definisi Makro Alokasi
  #define   alloc(vt,x) (vt*)malloc(sizeof(vt)*(x))
#endif
  
