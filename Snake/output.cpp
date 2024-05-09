#include <iostream>
#include <unistd.h>

int main(){
    for(int i = 0; i<100; i++){
        std::cout << i << "\n";
        sleep(1);
    }
}