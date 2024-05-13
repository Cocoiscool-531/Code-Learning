#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]){
  textbackground(BLUE);
  clrscr();
  textcolor(WHITE);
  gotoxy(30,5);
  cprintf("Hello World WHITE");
  textcolor(YELLOW);
  gotoxy(30,6);
  cprintf("Hello World YELLOW");
  for(int i=0;i<16;i++){
    textcolor(i);
    gotoxy(1,2+i);
    cprintf("Hello World");
    }
  getch();
  return 0;
  }