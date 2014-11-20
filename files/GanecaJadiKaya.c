/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : GanecaJadiKaya.c
  Tangggal  : 17 November 2014
  Deskripsi : Driver tubes.
*/

#include <stdio.h>
#include "alloc.h"

#define writeln printf("%c",10)

#define uint unsigned int
#define uchr unsigned char
#define usht unsigned short
#define ulng unsigned long

#define uchar unsigned char
#define ushrt unsigned short
#define ulong unsigned long

#define ushort unsigned short

#include "ADTTypeDef.h"    // definisi tipe yang akan dibentuk pada setiap ADT
#include "Queue_03.h"
#include "LinearList_03.h"

/* NOTE
  GAME STATE
  
  Login Data
  HighScore  :<UID,Held*,Worth>
  SaveGame   :<Queue of PlayerState>
  Player     :<UID,Name,SaveGame>
  
  Gameplay Variables
  PlayerState:<UID,Held,Worth>
  GamePlay   :<Queue of PlayerState>
  Field      :<BID,Zone,Name,Val>
  Board      :<Array of Field>
  
  #NOTE# 
    basically the held* means the held variable is not used as the purpose
    but the date base.
*/

// KAMUS GLOBAL
char saveName[18] = "ganecaAyoKaya.dat";

// Daftar Konstanta Enumeratif
typedef enum gState {
  gEnd, gUser, gHS, gGS } GanecaState;
  
// Daftar Tipe Bentukan
/* untuk sebagian tipe yang tidak muncul pada kamus utama, 
   dapat dibilang bahwa tipe tersebut sudah didefinisikan
   pada suatu ADT yang akan digunakan pada file ADTTypeDef.h */
typedef struct gSaveData {
  int       uid;
  Queue     gameState;
  gSaveData*nextData;
} saveGame;
typedef struct gSaveGame {
  saveGame* firstData;
} saveList;
typedef struct gHiScore  {
  tPlayer   data[10];
  uchar     size;
} gHiScore;

// Realisasi Fungsi dan Prosedur
void loadSaveData(FILE*saveFile,LLHead&dataBase,gHiScore&highScore,saveList&saveData) {
  GanecaState gsState;
  tUserData   newUser;
  gSaveData   newSaveLoad;
  uchar       gSaveSize;
  tPlayer     keptPlayer;
  
  saveFile    = fopen(saveName,"w");
  
  CreateEmptyList(dataBase);
  CreateEmptyQueue(saveData);
  
  newUser.uid = 0;
  highScore.size = 0;
  
  newSaveLoad.uid = 0;
  
  while(!feof(saveData)) {
    fscanf(saveFile,"%c.",gsState);
    switch(gsState) {
      // Userdata
      case gUser:
        fscanf(saveFile,"%s;",&newUser.name);
        newUser.uid++;
        LLInsertFinal(dataBase,newUser);
        break;
      // Highscore
      case gHS:
        fscanf(saveFile,"%s>%10u;",&highScore.data[highScore.size].PID,&highScore.data[highScore.size].worth);
        highScore.size++;
        break;
      // Save-Load
      case gGS:
        fscanf(saveFile,"%i=%i>",&newSaveLoad.uid,&gSaveSize);
        while(--gSaveSize) {
          fscanf(saveFile,"%u,%u,%u;",&uid,&hold,&worth);
        }
        break;
    }
  }
  free(newUser);
}
  
int main() {
  // KAMUS LOKAL
  // Daftar Variabel
  FILE *   GanecaFile;
  LLHead   GanecaUserDB;
  gHiScore GanecaHighScore;
  Queue    GanecaPlayers;
  saveList GanecaSaveGame;
  
  // ALGORITMA
  
  
  // END OF PROGRAM
  return false;
}
