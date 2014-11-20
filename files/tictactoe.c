/*
  Nama/NIM  : Irfan Gunawan / 18213027
  Nama file : tictactoe.c
  Tangggal  : 12 November 2014
  Deskripsi : Test sistem implementasi TicTacToe berdasarkan prototipe dari Ruby
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "Array_03.h"
#include "Matrice_03.h"

#define ANSI_home()        printf("\x1B[H")
#define ANSI_goto(x,y)     printf("\x1B[%d;%dH",(int)(y),(int)(x))
#define ANSI_up(lines)     printf("\x1B[%dA",(char)(lines))
#define ANSI_dn(lines)     printf("\x1B[%dB",(char)(lines))
#define ANSI_rg(cols)      printf("\x1B[%dC",(char)(cols))
#define ANSI_lf(cols)      printf("\x1B[%dD",(char)(cols))
#define ANSI_save()        printf("\x1B[s")
#define ANSI_load()        printf("\x1B[u")
#define ANSI_cls()         printf("\x1B[2J")
#define ANSI_clreol()      printf("\x1B[2K")
#define ANSI_set(x,y)      printf("\x1B[%d;%dm",(char)(x),(char)(y))
#define ANSI_videomode(nr) printf("\x1B[=%dh",(char)(nr))
#define ANSI_resetmode(nr) printf("\x1B[=%dl",(char)(nr))
#define ANSI_report()      printf("\x1B[6n")

// AI source : http://www.cs.jhu.edu/~jorgev/cs106/ttt.pdf

// TicTacToe Convention
/*
   0 1 2
   3 4 5
   6 7 8
*/

// Selector Position
#define getHorz(r) (r)%3
#define getVert(c) (c)/3
// Basic Mirroring
#define opposite(x) 8-(x)
#define horzflip(x) 2-((x)-((x)/3)*3)+((x)/3)*3
#define vertmirr(x) 6-((x)-((x)%3))+((x)%3)
// Clockwise Rotation
#define rotateRg(x) (((x)<3)?((x)*3) + 2):( ((x)<6)?( ((x)-3)*3 +1):((x)-6)*3))
#define rotateLf(x) rotateRg(opposite(x))
// Diagonal Reflection
#define diagLfRf(x) horzflip(rotateLf(x))
#define diagRgRf(x) vertmirr(rotateRg(x))
// Side Check
#define checkCorner(x) ((x)!=4)&((x)%2==0)
#define checkCenter(x) (x)
#define checkSide(x)   (x)%2==1
// Combo Check
// Definition (x,i) -> x is base coord, i is array elem index
#define comboHorz(x,i) (x)*3+(i)
#define comboVert(x,i) (i)*3+(x)
#define comboDiag(x,i) ((x)) ? (comboDgRg(x,i)) : (comboDgLf(x,i))
#define comboDgLf(x,i)   (i)*4
#define comboDgRg(x,i)   2+(i)*2

// Constants
Array ACorner,ASide,ACenter,ATemp;
CreateEmptyArray(&ACorner,4);
CreateEmptyArray(&ASide,4);
CreateEmptyArray(&ACenter,1);
CreateEmptyArray(&ATemp,5);
ArrayAppend(&ACorner,0); ArrayAppend(&ACorner,2); ArrayAppend(&ACorner,6); ArrayAppend(&ACorner,8);
ArrayAppend(&ASide,1); ArrayAppend(&ASide,3); ArrayAppend(&ASide,5); ArrayAppend(&ASide,7);
ArrayAppend(&ACenter,4);

enum eComboBase { AHorz, AVert, ADiag };

// Global Variables
unsigned char AILevel;

// Functions
Array getCombo(eComboBase ComboType, unsigned char ComboIndex) {
  Array c;
  char  i;
  CreateEmptyArray(&c,3);
  for(i=0;i<3;i++)
    ArrayAppend(&c,ComboType==AHorz?
                     comboHorz(ComboIndex,i):
                     (ComboType==AVert?
                       comboVert(ComboIndex,i):
                       comboDiag(ComboIndex,i)
                     )
               );
  return c;
}

Array getMinor(unsigned char x){
  Array minor;
  ArrayCopy(ArrayJoin(getCombo(AHorz,getHorz(x)),getCombo(AVert,getVert(x))),&minor);
  return minor;
}

Array adjacence(int x) {
  Array adj;
  char    i;
  CreateEmptyArray(&adj,4);
  switch(x) {
    case 0:
      ArrayAppend(&adj,1);
      ArrayAppend(&adj,3);
      break;
    case 2:
      ArrayAppend(&adj,1);
      ArrayAppend(&adj,5);
      break;
    case 1:
      ArrayAppend(&adj,0);
      ArrayAppend(&adj,2);
      ArrayAppend(&adj,4);
      break;
    case 3:
      ArrayAppend(&adj,0);
      ArrayAppend(&adj,4);
      ArrayAppend(&adj,6);
      break;
    case 4:
      ArrayAppend(&adj,1);
      ArrayAppend(&adj,3);
      ArrayAppend(&adj,5);
      ArrayAppend(&adj,7);
      break;
    case 5:
    case 6:
    case 7:
    case 8:
      ArrayCopy(adjacence(opposite(x)),&adj);
      for(i=0;i<ArrayNumElmt(adj);i++)
        ArraySetElmt(&adj,i,opposite(ArrayGetElmt(adj,i));
      break;
  }
  return adj;
};

void ComboStateNear(Array MoveAvail,Array PlayerState,unsigned char*iPos[]) {
  int i,j,k;
  bool H,V,D;
  Array CompareZone;
  iPos[0] = -1; iPos[1] = -1; iPos[2] = -1;
  CreateEmptyArray(&CompareZone,3);
  ArraySetNEff(&CompareZone,3);
  H = V = D = false;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboHorz(i,j));
    H |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 2)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 1);
    iPos[0] = (iPos[0]==0)?i:iPos[0];
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboVert(i,j));
    V |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 2)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 1);
    iPos[1] = (iPos[1]==0)?i:iPos[1];
  }
  for(i=0;i<2;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboDiag(i,j));
    D |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 2)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 1);
    iPos[2] = (iPos[2]==0)?i:iPos[2];
  }
  free(CompareZone.T);
}

bool WinStateNear(Array MoveAvail,Array PlayerState){
  int i,j,k;
  bool H,V,D;
  Array CompareZone;
  
  CreateEmptyArray(&CompareZone,3);
  ArraySetNEff(&CompareZone,3);
  H = V = D = false;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboHorz(i,j));
    H |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 2)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 1);
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboVert(i,j));
    V |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 2)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 1);
  }
  for(i=0;i<2;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboDiag(i,j));
    D |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 2)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 1);
  }
  free(CompareZone.T);
  return H|V|D;
}

bool WinStateFull(Array MoveAvail,Array PlayerState){
  int i,j,k;
  bool H,V,D;
  Array CompareZone;
  
  CreateEmptyArray(&CompareZone,3);
  ArraySetNEff(&CompareZone,3);
  H = V = D = false;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboHorz(i,j));
    H |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 3)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 0);
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboVert(i,j));
    V |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 3)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 0);
  }
  for(i=0;i<2;i++){
    for(j=0;j<3;j++)
      ArraySetElmt(&CompareZone,j,comboDiag(i,j));
    D |= (ArrayNumElmt(ArrayIntersect(PlayerState,CompareZone)) == 3)&&
        (ArrayNumElmt(ArrayIntersect(MoveAvail,CompareZone)) == 0);
  }
  free(CompareZone.T);
  return H|V|D;
}

void XOInput(Array*Moves, Array*Board, Array*User, char c, bool t) { // t (0 - nil, 1 - enemy, 2 - player)
  ANSI_goto((c+3)/3 * 2,2*(c%3)+2);
  ArraySetElmt(&Board,c,t)
  ArrayAppend(&User,c)
  ArrayDeleteElement(&Moves,c+1);
  printf("%c",(t == 2)?'O':((t==1)?'X':' '));
}

unsigned char checkStrategy(Array StateP1, Array StateP2, Array Moves, unsigned char TurnCount, bool turn) {
  // assume P2 is player side
  Array WinMove, AllMove;
  Array&Types[3];
  bool  fs, ip;      // ForceSolution | InPinch
  int   i, rd;       // Random Number
  unsigned char solT[3] // Solution Type
  ArrayCopy(Moves,&WinMove);
  ArrayCopy(Moves,&AllMove);
  fs = false;
  
  if (turn%2) { // asker plays first
    if (checkCorner(StateP2.T[0]))              // plays from corner
      if (checkCenter(StateP1.T[0]))            // ensure first move is center
        switch (ArrayNumElmt(StateP2)) {      // turn taken by P2
          case 1: WinMove = ArrayIntersect(WinMove,adjacence(opposite(StateP2.T[0])));
          break;
          default:
            fs = true;
        }
      else
        switch (ArrayNumElmt(StateP2)) {      // turn taken by P2
          case 1: WinMove = ArrayIntersect(WinMove,ACorner);
            break;
          case 2: WinMove = ArrayIntersect(WinMove,(rand() % 100 < AILevel)?ACorner:ACenter);
            break;
          case 3:
          case 4:
            fs = true;
            break;
        }
    else if (checkCenter(StateP2.T[0]))         // plays from center
      if (checkSide(StateP1.T[0]))              // player picks edges
        switch(ArrayNumElmt(StateP2)) {
          case 1: sp = ArrayIntersect(WinMove,ACorner);
          default:
            fs = true;
        }
      else if (checkCorner(StateP1.T[0]))       // player picks corner
        switch(ArrayNumElmt(StateP2)) {
          case 1:
            if (ArrayElmtExists(sp,opposite(StateP1.T[0]))) {
              ArrayNumElmt(&sp,1);
              ArraySetElmt(&sp,1,opposite(StateP1.T[0]));
            } else {
              fs = true;
            }
            break;
          default:
            fs = true;
        }
    else if (checkSide(StateP2.T[0])){          // plays from edges
      ATemp = adjacence(StateP2.T[0]);
      if (ArrayElmtExists(ATemp.StateP1.T[0])) // near corner
        switch(ArrayNumElmt(StateP2)) {
          case 1:
            WinMove = ArrayIntersect(WinMove,ArrayDifference(ATemp,ACenter));
            break;
          default:
            fs = true
        }
      else if ArrayElmtExists(adjacence(opposite(StateP2.T[0])),StateP1.T[0]) // far corner adjacence 
        switch(ArrayNumElmt(StateP2)) {
          case 1:
            WinMove = ArrayDifference(ArrayIntersect(WinMove,adjacence(opposite(StateP2.T[0]))),ACenter);
            break;
          default:
            fs = true;
        }
      else if opposite(StateP2.T[0]) == StateP1.T[0] // far side
        switch(ArrayNumElmt(StateP2)) {
          case 1:
            WinMove = ArrayDifference(ArrayIntersect(WinMove,adjacence(StateP1.T[0])),ACenter);
            break;
          default:
            fs = true;
        }
      else if ArrayElmtExists(ACenter,StateP1.T[0]) // center counter
        switch(ArrayNumElmt(StateP2)) {
          case 1:
            WinMove = ArrayDifference(WinMove,getMinor(StateP2.T[0]));
            break;
          case 2:
            WinMove = ArrayIntersect(WinMove,
                        ArrayUnion(
                          ArrayIntersect(getCombo(AHorz,getHorz(StateP2.T[0])),getCombo(AVert,getVert(StateP2.T[1]))),
                          ArrayIntersect(getCombo(AHorz,getHorz(StateP2.T[1])),getCombo(AVert,getVert(StateP2.T[0])))
                        )
                      );
          break;
          default:
          fs = true;
        }
      else
        fs = true;
    else {                               // first turn
      // put input randomly
      Types[0] = ACorner
      Types[1] = ACenter
      Types[2] = ASide
      rd = rand() % 100
      WinMove = *Types[floor(rd/100.0 * rd/100.0 * 3)];
      // this algorithm ensures that corners are being prioritized
      // while it's still possible to put it either on center or  
      // even edge!
    // END OF IF < CheckCorner,CheckCenter,CheckSide,ManualDisjoint >
  else //player plays first
    if checkCorner(StateP1.T[0]) // corner start
      switch(ArrayNumElmt(StateP1)) {
        case 1: case 2: WinMove = ArrayIntersect(WinMove,ACenter); break;
        default:
          fs = true;
      }
    else if checkCenter(StateP1.T[0])  // center start
      switch(ArrayNumElmt(StateP1)) {
        case 1: case 2: WinMove = ArrayIntersect(WinMove,ACorner); break;
        default:
          fs = true;
      }
    else if checkSide(StateP1.T[0])   // edge start
      switch(ArrayNumElmt(StateP1)) {
        case 1: WinMove = ArrayIntersect(WinMove,ACenter); break;
        default:
          WinMove = ArrayIntersect(WinMove,
                      ArrayUnion(
                        ArrayIntersect(getCombo(AHorz,getHorz(StateP1.T[0])),getCombo(AVert,getVert(StateP1.T[1]))),
                        ArrayIntersect(getCombo(AHorz,getHorz(StateP1.T[1])),getCombo(AVert,getVert(StateP1.T[0])))
                      )
                    );
      }
    // disjoint without else, because always true either one of them
    // END OF IF < CheckCorner,CheckCenter,CheckSide,AutoDisjoint >
  // END OF IF
  if fs || (TurnCount >= 5 && (rand() % 100) < AILevel) {     // if force-solution flag raised
    //puts "Find Solution!"
    //puts "Possible moves: #{sp}"
    ArrayCopy(AllMove,&WinMove);
    if WinStateNear(WinMove,StateP2) {
      ComboStateNear(WinMove,StateP1,&iPos);
      for(i=2;i>=0;i--)
        if(iPos[i]>=0) {
          ArrayIntersect(WinMove,getCombo(i,iPos[i]));
          break;
        }
    }
  }
  if nextPosWin(histP) then
    #puts "In a pinch!"
    sp = sa
    #puts "Possible moves: #{sp.map(&:succ)}"
    hz = [0,1,2].find{|i|      (sp&horz(i)).size == 1 && (s1&horz(i)).size == 2}
    vr = [0,1,2].find{|i|      (sp&vert(i)).size == 1 && (s1&vert(i)).size == 2}
    dg = [false,true].find{|i| (sp&diag(i)).size == 1 && (s1&diag(i)).size == 2}
    #puts "Possible chance: H#{hz ? hz : '-'} V#{vr ? vr : '-'} D#{dg.nil? ? '-' : (dg ? '\\' : "/")}"
    if dg.nil?   # not found solution on diagonal
      if vr.nil? #     found solution on horizontal
        if !hz.nil?
          sp &= horz(hz)
        end
      else       #     found solution on vertical
        sp &= vert(vr)
      end
    else         #     found solution on diagonal
      sp &= diag(dg)
    end
  end
  
  rd = (rand < @level && sp.size > 0)
  puts rd ? "Best Solution" : "Random Solution"
  rd ? sp : sa
}
