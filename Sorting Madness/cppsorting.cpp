#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
//#include <GL/glew.h>
//#include <GLFW/glwf3.h>
//#include <glm/glm.hpp>
#define CONFIG_FILE_PATH "./sorting.cfg"

//using namespace glm;

// CONFIG READING
uint ELEMENTS;
uint     RAND_MODE;

bool configRead(){
    std::fstream in;
    in.open(CONFIG_FILE_PATH, std::ios::in);

    if (!in.is_open()){ 
        return false;
    }

    bool loop = true;
    bool RAND_MODESet = false;
    bool elementSet = false;

    while(loop){
        std::string curLine;
        std::getline(in, curLine);

        std::string parsedNum;
        if(curLine.find("RAND_MODE=")!= std::string::npos){
            for(char& c : curLine){
                if(c >= '0' && c <= '9'){
                    parsedNum += c;
                }
            }
            RAND_MODE = stoi(parsedNum);
            parsedNum.clear();
            RAND_MODESet = true;
        }
        if(curLine.find("ELEMENTS=")!=std::string::npos){
            for(char& c : curLine){
                if(c >= '0' && c <= '9'){
                    parsedNum += c;
                }
            }
            ELEMENTS = stoi(parsedNum);
            parsedNum.clear();
            elementSet = true;
        }
        if(RAND_MODESet && elementSet){break;}

    }

    return true;
}

// Counter for how many attempts it takes to sort, primarily used in bogo sort
int iterations = 0;

// Check if vector is sorted
bool sorted(std::vector<int> ls) {
    for(int i=1;i<ls.size();i++){
        if(ls[i] < ls[i-1]){
            return false;
        }
    }
    return true;
}

// Return a random int between min and max inclusive
int randInt(int min,int max){
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(min, max-1);

    return distr(generator);
}

// Assist in print a vector
int printL(std::vector<int> ls){
    for(int i = 0; i < ls.size(); i++){
        int x = ls[i];
        if(i != ls.size()-1){
            std::cout << x << ", ";  
        }else{
            std::cout << x;
        }
            
        }
    return 0;
}

int visualVector(std::vector<int> vector){

}

// Randomizes a sequential vector (see RAND_MODE above for more info)
std::vector<int> seqRandomize(std::vector<int> sorted){
    int len = sorted.size();
    int max = sorted.size();
    std::vector<int> random;
    random.resize(len);
    for(int i=0;i<len;i++){
        int x = randInt(0,max);
        random[i] = sorted[x];
        sorted.erase(sorted.begin()+x);
        max--;
    }
    return random;
}

// Creates a random vector with [ELEMENTS] ELEMENTS and a max value of [RAND_MODE] for each element
std::vector<int> creRandomize(){
    std::vector<int> random;
    for(int i=0;i<=ELEMENTS;i++){
        random.push_back(randInt(0,RAND_MODE));
    }
    return random;
}

// SILLY SORTS BELOW:

/* Slalin Sort:
* If a number is less then the previous number, delete it. Repeat until sorted (minor data loss)
*/
std::vector<int> stalin(std::vector<int> unsorted){
    for(int i=1;i<unsorted.size(); i=i){
        int cp = unsorted[i];
        int bp = unsorted[i-1];
        if(cp<bp){
            unsorted.erase(unsorted.begin()+i);
        }else{
            i++;
            }
    }
    return unsorted;
}

/* Bogo Sort:
* If the vector is sorted, return the vector. Else, randomize the list. Repeat until sorted
*/
std::vector<int> bogo(std::vector<int> unsorted){
    while(!sorted(unsorted)){
        unsorted = seqRandomize(unsorted);
        iterations++;
        std::cout << iterations << "\n";
    }
    std::cout << "\n \n Sorted! Only took " << iterations << " attempts! \n \n";

    return unsorted;
}

// SERIOUS SORTS NOW:

/* Bubble Sort:
* Compare 2 places at a time, if value of pointer 2 is less than value of pointer 1, 
* swap them. If value of pointer 2 is greater than value of pointer 1, increment poth 
* pointers Repeat until sorted
*/
std::vector<int> bubble(std::vector<int> unsorted){
    while(!sorted(unsorted)){
        for(int i=0;i<unsorted.size()-1;i++){
            int p1 = unsorted[i];
            int p2 = unsorted[i+1];
            if(p2<p1){
                unsorted[i+1] = p1;
                unsorted[i] = p2;
            }
        }
    }
    return unsorted;
}

// The main code. If you needed a comment to understand what "main" means, I don't know what to say.
int main() {
    configRead();

    std::vector<int> sorted;
    std::vector<int> unsorted;
    sorted.resize(ELEMENTS);
    if(RAND_MODE==0){
        for(int i = 0; i < ELEMENTS; i++){
            sorted[i] = i;
        }
        unsorted = seqRandomize(sorted);
    }else{
        unsorted = creRandomize();
    }
    std::vector<int> resorted = bogo(unsorted);
    printL(resorted);
}