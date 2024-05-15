#include <conio.h>
#include <iostream>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128

Console conio;

int main(int argc, char *argv[]){
  int i = 0;
  while(true){
    i++;
    std::string consoleText;
    std::cin >> consoleText;
    conio.getch();
    std::cout << "Hello Test " << consoleText << "!\n";
  }
  }