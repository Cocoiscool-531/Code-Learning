#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#define CONFIG_FILE_PATH "./key.cfg"

// 0=custom, 1=reverse. If ceaser=true, mode=mode
int mode;
bool isCeaser;

const std::vector<std::string> abc({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"});
const std::vector<std::string> zyx({"z","y","x","w","v","u","t","s","r","q","p","o","n","m","l","k","j","i","h","g","f","e","d","c","b","a"});
std::vector<std::string> customKey;
bool configRead(){
    std::fstream cfg;
    cfg.open(CONFIG_FILE_PATH, std::ios::in);

    if (!cfg.is_open()){ 
        return false;
    }

    bool modeSet = false;

    while(true){
        std::string curLine;
        std::getline(cfg, curLine);

        std::string parsedNum;
        if(curLine.find("Method=")!= std::string::npos && !modeSet){
            if(curLine.find("Method=\"Custom\"")!= std::string::npos ){
                mode=0;
            }else if(curLine.find("Method=\"Reverse\"")!= std::string::npos ){
                mode=1;
            }
            else{
                for(char& c : curLine){
                    if(c >= '0' && c <= '9'){
                        parsedNum += c;
                    }
                }
                mode = stoi(parsedNum);
                isCeaser = true;
                parsedNum.clear();
            }
            modeSet = true;
        }
    }
    return true;
}

bool customInit(){
    customKey.resize(35);
    int custKeyPointer = 0;
    std::fstream cust;
    cust.open(CONFIG_FILE_PATH, std::ios::in);

    if(cust.is_open()!=true){return false;}
    bool startCustKey;
    while(true){
        std::string curLine;
        std::getline(cust,curLine);

        if(curLine.find("a=")){
            startCustKey = true;
        }

        if(startCustKey && custKeyPointer <= 35){
            customKey[custKeyPointer] = (curLine[2]);
            custKeyPointer++;
        }
    }
}

bool custom(){
    customInit();
    return true;
}

bool reverse(){return true;}

bool ceaser(int shift){return true;}

int main(){
    configRead();
    if(isCeaser==false&&mode==0){
        custom();
    }
    return 0;
}