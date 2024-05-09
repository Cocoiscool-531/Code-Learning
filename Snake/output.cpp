#include <iostream>
#include <unistd.h>

int main(){
    for(int i = 0; i<10; i++){
        std::cout << i << "\n";
        sleep(1);
    }
}