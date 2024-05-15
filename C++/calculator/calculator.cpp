#include <iostream>
#include <math.h>
#include <string>
#include <vector>

int main(){
    std::vector<float> original;
    std::cout << "Please Enter Each Number, press enter after each. Only floats. Press enter with \"end\" finish.\n";
    bool loopActive = true;
    while(loopActive){
        std::string input;
        int inputInt;
        std::cin >> input;
        if(input=="end"){
            break;
        }else{
            std::string parsedNum;
            for(char& c : input){
                    if(c >= '0' && c <= '9'){
                        parsedNum += c;
                    }
            inputInt = std::stoi(parsedNum);
            original.push_back(inputInt);
        }
    }
    std::cout << original;
}