#include <iostream>
#include <math.h>
#include <string>
#include <vector>

int main(){
    std::vector<float> original;
    std::cout << "Please Enter Each Number, press enter after each. Only floats. Press enter with nothing to finish.\n";
    bool loopActive = true;
    while(loopActive){
        std::string input;
        int inputInt;
        std::cin >> input;
        inputInt = std::stoi(input);
        original.push_back(inputInt);
    }
}