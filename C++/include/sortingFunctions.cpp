#include <vector>
#include <random>
#include <iostream>
#include <sortingFunctions.h>

// Check if a vector is sorted.
bool intSorted(std::vector<int> ls) {
    for(int i=1;i<ls.size();i++){
        if(ls[i] < ls[i-1]){
            return false;
        }
    }
    return true;
}
bool floatSorted(std::vector<float> ls) {
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

std::vector<int> intBubble(std::vector<int> unsorted){
    while(!intSorted(unsorted)){
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
std::vector<float> floatBubble(std::vector<float> unsorted){
    while(!floatSorted(unsorted)){
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

// Assist in print a vector
int intPrintL(std::vector<int> ls){
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

int floatPrintL(std::vector<float> ls){
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