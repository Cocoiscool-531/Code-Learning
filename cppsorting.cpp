#include <iostream>
#include <vector>
#include <random>

using namespace std;
bool sorted(vector<int> ls) {
    for(int i=1;i<ls.size();i++){
        if(ls[i] < ls[i-1]){
            return false;
        }
    }
    return true;
}

int randInt(int min,int max){
    random_device                  rand_dev;
    mt19937                        generator(rand_dev());
    uniform_int_distribution<int>  distr(min, max-1);

    return distr(generator);
}

int printL(vector<int> ls){
    for(int i = 0; i < ls.size(); i++){
        int x = ls[i];
        if(i != ls.size()-1){
            cout << x << ", ";  
        }else{
            cout << x;
        }
        if(i==20 || i==40 || i==60 || i==80){
            cout << "\n";
        }
            
        }
    return 0;
}

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

vector<int> randomize(vector<int> sorted){
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

int main() {
    vector<int> sorted;
    sorted.resize(101);
    for(int i = 0; i < 101; i++){
        sorted[i] = i;
    }
    vector<int> unsorted = randomize(sorted);
    vector<int> resorted = stalin(unsorted);
    printL(resorted);
}