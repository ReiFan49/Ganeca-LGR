Ganeca-LGR
==========
git commit -m <message>
  kasih status dari perubahan yang kalian lakuin

coba -> try.github.io/levels/1/challenges
  kalo bingung

=== Struktur data game ===
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

Game Data File Format
(no \n)
gStart.
gUser.
  userName;userName;....
gHS.
  userName>score,date;userName>score,date;...
gGS.
  userID=playerSize>
    playerID,playerHold,playerWorth;
    playerID,playerHold,playerWorth;
    ....
  userID=playerSize>
    ...
  ...

#NOTE# 
  gStart,gUser,gHS,gGS are marker.
  date uses held variable on highscore tuple,
    which consists YYYYMMDD format

=== PEMBAGIAN KERJA ===
Main Menu
  Init
    Load File
  Sel
    Register
    Login
    Highscore
    Quit
  End
    Save File
  (sistem penggunaan menu entar gw kasih, dari driver ADT gw)

Register
  uid always incrementing overtime, make sure there's a procedure
    to handle this.

Login
  userName should exists on the list
  if yes, go to Game Preparation Screen

Highscore
  Show highscore (psuedo code)
    printf("%-32s %4i/%2i/%2i %-10i%c",Username,YYYY,MM,DD,Worth,10);

Game Preparation
  New Game
  Load Game
  Logout

New Game
  Init
  Sel
    vs Player
    vs Player+AI
  Proc
    how many players that play?
    could you tell me the name of the player that you challenge?
    (AI will have autogenerated name, only enter allowed)
  End

Load Game
  Exists
    Load or No?
  Not Exists
    Prompt.

Board Building
  i'll prefer about ASCII manipulation,
  i have the code, check tictactoe.c for the detail of the code
  on header section, iirc.

Gameplay
  I'm still thinking about this  