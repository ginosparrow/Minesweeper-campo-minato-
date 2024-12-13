#include "plusconio.h"
#include <windows.h>//aggiunge funzioni per windows
#include <stdlib.h> // Per la funzione system()

void textcolor(int textColor, int bgColor) {//funzione per cambiare colore al testo e al suo sfondo 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void clrscr(){
    system("cls");
}