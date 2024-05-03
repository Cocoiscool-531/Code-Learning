#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <fstream>
#define CONFIG_FILE_PATH "./CONFIG.cfg"

using namespace std;

// CONFIG READING
uint ELEMENTS;
uint     RAND_MODE;

bool configRead(){
    fstream in;
    in.open(CONFIG_FILE_PATH, ios::in);

    if (!in.is_open()){ 
        return false;
    }

    bool loop = true;
    bool RAND_MODESet = false;
    bool elementSet = false;

    while(loop){
        string curLine;
        getline(in, curLine);

        string parsedNum;
        if(curLine.find("RAND_MODE=")!=string::npos){
            for(char& c : curLine){
                if(c >= '0' && c <= '9'){
                    parsedNum += c;
                }
            }
            RAND_MODE = stoi(parsedNum);
            parsedNum.clear();
            RAND_MODESet = true;
        }
        if(curLine.find("ELEMENTS=")!=string::npos){
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
bool sorted(vector<int> ls) {
    for(int i=1;i<ls.size();i++){
        if(ls[i] < ls[i-1]){
            return false;
        }
    }
    return true;
}

// Return a random int between min and max inclusive
int randInt(int min,int max){
    random_device                  rand_dev;
    mt19937                        generator(rand_dev());
    uniform_int_distribution<int>  distr(min, max-1);

    return distr(generator);
}

// Assist in print a vector
int printL(vector<int> ls){
    for(int i = 0; i < ls.size(); i++){
        int x = ls[i];
        if(i != ls.size()-1){
            cout << x << ", ";  
        }else{
            cout << x;
        }
            
        }
    return 0;
}

// Randomizes a sequential vector (see RAND_MODE above for more info)
vector<int> seqRandomize(vector<int> sorted){
    int len = sorted.size();
    int max = sorted.size();
    vector<int> random;
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
vector<int> creRandomize(){
    vector<int> random;
    for(int i=0;i<=ELEMENTS;i++){
        random.push_back(randInt(0,RAND_MODE));
    }
    return random;
}

// SILLY SORTS BELOW:

/* Slalin Sort:
* If a number is less then the previous number, delete it. Repeat until sorted (minor data loss)
*/
vector<int> stalin(vector<int> unsorted){
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
vector<int> bogo(vector<int> unsorted){
    while(!sorted(unsorted)){
        unsorted = seqRandomize(unsorted);
        iterations++;
        cout << iterations << "\n";
    }
    cout << "\n \n Sorted! Only took " << iterations << " attempts! \n \n";

    return unsorted;
}

// SERIOUS SORTS NOW:

/* Bubble Sort:
* Compare 2 places at a time, if value of pointer 2 is less than value of pointer 1, 
* swap them. If value of pointer 2 is greater than value of pointer 1, increment poth 
* pointers Repeat until sorted
*/
vector<int> bubble(vector<int> unsorted){
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

    vector<int> sorted;
    vector<int> unsorted;
    sorted.resize(ELEMENTS);
    if(RAND_MODE==0){
        for(int i = 0; i < ELEMENTS; i++){
            sorted[i] = i;
        }
        unsorted = seqRandomize(sorted);
    }else{
        unsorted = creRandomize();
    }
    vector<int> resorted = bogo(unsorted);
    printL(resorted);
}