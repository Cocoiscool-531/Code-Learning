#include <iostream>
#include <vector>

using namespace std;
bool sorted(vector<int> ls) {
    for(int i=1;i<=ls.size();i++){
        if(ls[i] < ls[i-1]){
            return false;
        }
    return true;
    }
}

int printL(vector<int> ls){
    for(int i = 0; i < ls.size(); i++){
        int x = ls[i];
        if(i != ls.size()-1){
            cout << ls[x] << ", ";  
        }else{
            cout << ls[x];
        }
        if(i==20 || i==40 || i==60 || i==80){
            cout << "\n";
        }
            
        }
    return 0;
}

int main() {
    vector<int> unsorted;
    unsorted.resize(101);
    for(int i = 0; i < 101; i++){
        unsorted[i] = i;
    }
    printL(unsorted);
    cout << "\n" << "\n" << (sorted(unsorted));
    }