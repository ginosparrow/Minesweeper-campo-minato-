#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "plusconio.c"

#define SIZE 10
/*
tasti speciali
q =  113
enter = 13
back_space = 8
su = 072
giu = 080
sx = 075
dx = 077
*/
/*
caratteri speciali 
coroce = 43
*/

/*
colori 
  0 = Nero       8 = Grigio
    1 = Blu scuro        9 = Blu
    2 = Verde       10 = Verde limone
    3 = Verde acqua        11 = Azzurro
    4 = Bordeaux         12 = Rosso
    5 = Viola      13 = Fucsia
    6 = Verde oliva      14 = Giallo
    7 = Grigio chiaro       15 = Bianco
*/



void info();
void menu();
void terreno_refresh(int x, int y, int stato);
void non_va();
void puntatore();
void prova();
void random();
void terreno_cls();
void terreno_s_cls();
void numero_mine();
void comandi();
void vittoria();
void looser();
int coppia_esiste(int x[], int y[], int lunghezza, int a, int b);

int tasto = 0;//tasto premuto
int rig = 10;
int col = 10;
int n_mine = 0;


int bombe_x [10];//arry per cordinate mine
int bombe_y [10];//^^^^^^^^^^^^^^^^^^^^^^^^

char terreno[10][10]= {
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'},
  {'0','0','0','0','0','0','0','0','0','0'}
};
char terreno_sadow[10][10]= {
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'},
  {'r','r','r','r','r','r','r','r','r','r'}
};

int main(){
  srand(time(NULL));

  menu();
  return 0;
}

void menu(){//menu del softwer
  clrscr();// pulisce lo schermo 
  textcolor(3, 0);//colore del testo 
  printf("Menu\n");
  textcolor(14, 0);
  printf("[*] start\n");
  textcolor(7, 0);
  printf("[ ] info\n");
  printf("[ ] quit\n");

  

  int index = 0;//indice della lista del menu
  int i = 1;//verifica del ciclo while 

  while (i == 1){

    n_mine =0;
    terreno_cls();
    terreno_s_cls();

    tasto = getch();//legge tasto premuto senza pasare per il buffer
    if (tasto == 72 && index > 0){//controlla che il tasto premuto sia la freccia su(72) e il numero in index sia sempre maggiore di 0
      index--;
    }else if (tasto == 80 && index < 2){//controlla che il tasto premuto sia la freccia su(80) e il numero in index sia sempre minore di 2
      index++;
    }else if(tasto == 13){//contorlla se il tasto invio/enter(13) e stato premuto 

      switch (index)//controlla l'index e va a attivare la funzione del menu corrispondente
      {
      case 0:
        random(1, 9);
        comandi();
        puntatore();
        
        i = 0;
        break;
      case 1:
        info();
        i = 0;
        break;
      case 2:
        tasto = 113;
        i = 0;
        break;
      }
      
    }
    

  switch (index){//controlla il valore di index per aggiornale il menu
    case 0:
      clrscr();
      textcolor(3, 0);
      printf("Menu\n");
      textcolor(14, 0);
      printf("[*] start\n");
      textcolor(7, 0);
      printf("[ ] info\n");
      printf("[ ] quit\n");
      break;
    case 1:
      clrscr();
      textcolor(3, 0);
      printf("Menu\n");
      textcolor(7, 0);
      printf("[ ] start\n");
      textcolor(14, 0);
      printf("[*] info\n");
      textcolor(7, 0);
      printf("[ ] quit\n");
      break;
    case 2:
      clrscr();
      textcolor(3, 0);
      printf("Menu\n");
      textcolor(7, 0);
      printf("[ ] start\n");
      printf("[ ] info\n");
      textcolor(14, 0);
      printf("[*] quit\n");
      textcolor(7, 0);
      break;
    }
  }
}

void non_va(){//megaio di errore
  textcolor(0, 12);
  printf("!");
  textcolor(14,0);
  printf("Ancora in fase di sviluppo");
  textcolor(0,12);
  printf("!");
  textcolor(7,0);
  getch();
}

void info(){//pagina delle info
  clrscr();
  textcolor(14, 0);
  printf("INFO\n");
  textcolor(7,0);
  printf("Questa riproduzione non fedele di Prato Fiorito,\n fatta semplicemente per scopo amatoriale.\n");
  printf("\n\t\t comandi di gioco\n");
  printf("\n\n\n\tW = up\n\tS = down\n\tA = left\n\tD = rigth\n\tK = scopri cosa c'%c sotto al terreno e togli le mine\n\tL = applicha bandiere le mine ", 138);
  
  textcolor(0,14);
  printf("\n\n\n\t[menu]\t");
  textcolor(7,0);
  printf("\t[quit]");

  int r = 0;
  int g = 0;
  while (r == 0){
    tasto = getche();
    if (tasto == 75){//tassto freccia sinistra (75)
      clrscr();
      textcolor(14, 0);
      printf("INFO\n");
      textcolor(7,0);
      printf("Questa riproduzione non fedele di Prato Fiorito,\n fatta semplicemente per scopo amatoriale.\n");
      printf("\n\t\t comandi di gioco\n");
      printf("\n\n\n\tW = up\n\tS = down\n\tA = left\n\tD = rigth\n\tK = scopri cosa c'%c sotto al terreno e togli le mine\n\tL = applicha bandiere le mine ", 138);
      textcolor(0,14);
      printf("\n\n\n\t[menu]\t");
      textcolor(7,0);
      printf("\t[quit]");
      g = 0;
    }else if (tasto == 77){//tasto freccia destra (77)
      clrscr();
      textcolor(14, 0);
      printf("INFO\n");
      textcolor(7,0);
      printf("Questa riproduzione non fedele di Prato Fiorito,\n fatta semplicemente per scopo amatoriale.\n");
      printf("\n\t\t comandi di gioco\n");
      printf("\n\n\n\tW = up\n\tS = down\n\tA = left\n\tD = rigth\n\tK = scopri cosa c'%c sotto al terreno e togli le mine\n\tL = applicha bandiere le mine ", 138);
      printf("\n\n\n\t[menu]\t");
      textcolor(0,14);
      printf("\t[quit]");
      textcolor(7,0);
      g = 1;
    }

    if (tasto == 13){//premuto il tasto invio 
      if(g == 0){
        menu();//sitorna al menuo fermado il cilo while 
        r = 1;
      }else if(g == 1){// termina il ciclo while
        r = 1;
      }
    } 
  }
}

/*
╔═══╦═══╦═══╦═══╦═══╗
║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║
╚═══╩═══╩═══╩═══╩═══╝
*/
void terreno_refresh( int x , int y, int stato){
  clrscr();

  printf("%c", 201);//cornice superiore
  for(int i = 0; i < 39; i++){
    if ((i+1)%4 == 0){
      printf("%c",203 );
    }else{
      printf("%c", 205);
    }
  }
  printf("%c\n",187);


  
  for (int r= 0; r < col; r++){//tutto cio che è in mezzo 
    printf("%c", 186);
    for (int c = 0; c < rig; c++){
      
      if (r == y && c == x)
      {
        textcolor(0,3);
        printf(" x ");
        textcolor(7,0);
      }else{
        char e = terreno_sadow[r][c];
        switch (e)
        {
        case '0'://vuoto
          textcolor(0,0);
          printf(" %c ", terreno_sadow[r][c]);
          textcolor(7,0);
          break;
        case '*'://mine
          textcolor(12,0);
          printf(" %c ", terreno_sadow[r][c]);
          textcolor(7,0);
          break;
        case '1':
          textcolor(10,0);
          printf(" %c ", terreno_sadow[r][c]);
          textcolor(7,0);
          break;
        case '2':
          textcolor(9,0);
          printf(" %c ", terreno_sadow[r][c]);
          textcolor(7,0);
          break;
        case '3':
          textcolor(6,0);
          printf(" %c ", terreno_sadow[r][c]);
          textcolor(7,0);
          break;
        case 'r':
          textcolor(0,8);
          printf(" %c ", terreno_sadow[r][c]);
          textcolor(7,0);
          break;
        
        default:
          textcolor(13,0);
          printf(" %c ", terreno_sadow[r][c]);
          textcolor(7,0);
          break;
        }
        
      }
    
      printf("%c", 186);
    }
    printf("\n", 186);
    if(r != 9){
      printf("%c", 204);//cornice tra una riga di numeri e l'altra 
      for(int i = 0; i < 39; i++){
        if ((i+1)%4 == 0){
          printf("%c", 206);
        }else{
          printf("%c", 205);
        }
      }
      printf("%c\n",185);
    }

    
  }

  printf("%c", 200);//cornice inferiore
  for(int i = 0; i < 39; i++){
    if((i+1)%4 == 0){//% serve per calcorale se un numero e multipo di 4
      printf("%c", 202);
    }else{
      printf("%c", 205);
    }
    
  }
  printf("%c\n",188);

  if(stato == 1){
        vittoria();
    }else if(stato == 2){
        looser();
    }
  
  printf(" mine: %d\n", n_mine);

  /*for (int f = 0; f < 10; f++)
    {
      printf("%d : %d \n", bombe_x[f], bombe_y[f]);
    }*/
}

void puntatore(){//sposta le cordinate dei puntatore
  int t = 0; //tiene il ciclo while attivo 
  int x = 0, y = 0;//cordinate 
  int stato  = 0;
  terreno_refresh(x, y, stato);

  while (t == 0){
    

    tasto = getche();//recupero tasto

    switch (tasto){
      case 119://tastro w
        if(y > 0)y--;
        break;
      case 72://tastro su
        if(y > 0)y--;
        break;
      case 80://tastro giù
        if(y < 9)y++;
        break;
      case 115://tastro s
        if(y < 9)y++;
        break;
      case 75://tastro sx
        if (x > 0)x--;  
        break;
      case 97://tastro a
        if (x > 0)x--;  
        break;
      case 77://tastro dx
        if (x < 9)x++; 
        break;
      case 100://tastro d
        if (x < 9)x++; 
        break;
      case 107://tastro k 
        if(terreno_sadow[y][x] == '>'){
          n_mine--;
          terreno_sadow[y][x] = 'r';

        }else if(terreno[y][x] == '*'){//contorlla se vene trovata una mina
          //printf("hai perso");
          stato = 2;
          terreno_refresh(x, y, stato);
          getche();
          t = 1;
          menu();

        }else{
         terreno_sadow[y][x] = terreno[y][x];
        }
        break;
      case 108://tastro l
        if (terreno_sadow[y][x] != '>'){
          terreno_sadow[y][x] = '>';
           n_mine++;
        }

        break;
      case 113:
        t = 1;
        menu();
        break;


    }  

    int m = 0;

    for (int c = 0; c< 10; c++){
      for (int r = 0; r < 10; r++)
      {
        if(terreno_sadow[c][r] == '>' && terreno[c][r] == '*'){ 
          m++;
        }
      }
      
    }

    if (m == 10){//contorllo che le bandire combacion con le bombe
      int gg = 0;
      for (int r = 0; r < 10; r++){
        for (int c = 0; c < 10; c++){
            if (terreno_sadow[bombe_x[c]][bombe_x[r]] == '>')
            {
              gg++;
            }
            if (gg == 10 && n_mine == 10){//se tute le  badiere combaciano e arrivano a 10 hai vinto 
              //printf("hai vinto!!");
              stato = 1;
              terreno_refresh(x, y, stato);
              getche();
              t = 1;
              menu();
            }
            
        }
        
      }
      
    } 

   terreno_refresh(x, y, stato);
  }

  

}

void prova(){//serve per fare prove

  clrscr();
  for (int r = 0; r < rig; r++){
    for (int c = 0; c < col; c++){
      printf("%c", terreno_sadow[r][c]);
    }
    printf("\n");
  }
  getche();
}

int coppia_esiste(int x[], int y[], int lunghezza, int a, int b) {
    for (int i = 0; i < lunghezza; i++) {
        if (x[i] == a && y[i] == b) {
            return 1; // Coppia già esistente
        }
    }
    return 0; // Coppia non trovata
}

void random(int min, int max){
    terreno_cls();//ripulise terreno 
 
    int i = 0;


    while (i < SIZE) {
        // Genera numeri casuali per x e y
        int num_x = rand() % 10; // Numeri casuali tra 0 e 10
        int num_y = rand() % 10;

        // Controlla se la coppia (num_x, num_y) è unica
        if (!coppia_esiste(bombe_x, bombe_y, i, num_x, num_y)) {
            bombe_x [i] = num_x;
            bombe_y[i] = num_y;
            i++;
        }
    }

  for(int r = 0; r < 10; r++){//inserice le mine nele cordiante randomizate
      terreno[bombe_x[r]][bombe_y[r]] = '*';
    }
  numero_mine();
}

void terreno_cls(){//ripulisce il terreno 
  for (int r = 0; r < 10; r++){
    for (int c = 0; c < 10; c++){
      terreno[r][c] = '0';
    }
  } 
}

void terreno_s_cls(){//ripulisce il terreno_scadow 
  for (int r = 0; r < 10; r++){
    for (int c = 0; c < 10; c++){
      terreno_sadow[r][c] = 'r';
    }
  } 
}

void numero_mine(){//inserice i numeri intorno a le mine incirmeteado se tocca più di una mina
  for (int r = 0; r < 10; r++){
    if (terreno[bombe_x[r]][bombe_y[r] +1] != '*' && bombe_y[r] < 9){
      terreno[bombe_x[r]][bombe_y[r]+1]++;

    }
    if (terreno[bombe_x[r]][bombe_y[r] -1] != '*' && bombe_y[r] > 0){
      terreno[bombe_x[r]][bombe_y[r] -1]++;

    }
    if (terreno[bombe_x[r]+1][bombe_y[r]] != '*' && bombe_x[r] < 9){
      terreno[bombe_x[r]+1][bombe_y[r]]++;

    }
    if (terreno[bombe_x[r]-1][bombe_y[r]] != '*' && bombe_x[r] > 0){
      terreno[bombe_x[r]-1][bombe_y[r]]++;

    }
    if (terreno[bombe_x[r]+1][bombe_y[r]-1] != '*' && bombe_x[r] < 9 && bombe_y[r] > 0){
      terreno[bombe_x[r]+1][bombe_y[r]-1]++;

    }
    if (terreno[bombe_x[r]+1][bombe_y[r]+1] != '*' && bombe_x[r] < 9 && bombe_y[r] <9){
      terreno[bombe_x[r]+1][bombe_y[r]+1]++;

    }
    if (terreno[bombe_x[r]-1][bombe_y[r]-1] != '*' && bombe_x[r] > 0 && bombe_y[r] > 0){
      terreno[bombe_x[r]-1][bombe_y[r]-1]++;

    }
    if (terreno[bombe_x[r]-1][bombe_y[r]+1] != '*' && bombe_x[r] > 0 && bombe_y[r] < 9){
      terreno[bombe_x[r]-1][bombe_y[r]+1]++;

    }
  }
}

void comandi(){
  clrscr();
  printf("\n\n\n\tW = up\n\tS = down\n\tA = left\n\tD = rigth\n\tK = scopri cosa c'%c sotto al terreno e togli le mine\n\tL = applichi le mine\n\n\nPremi un tasto per continuare... ", 138);
  getch();
}


void vittoria(){
  textcolor(0,14);
  printf("                                  \n");
  printf("           Hai vinto!!!           \n");
  printf("                                  \n");
  textcolor(7,0);
  printf("Premi un tasto per tornare al menu\n");
}
void looser(){
  textcolor(0,12);
  printf("                                  \n");
  printf("           Hai perso!!!           \n");
  printf("                                  \n");
  textcolor(7,0);
  printf("Premi un tasto per tornare al menu\n");
}