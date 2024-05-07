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
std::string encrypted;

const std::string abc = "abcdefghijklmnopqrstuvwxyz";
const std::string zyx = "zyxwvutsrqponmlkjihgfedcba";
const std::string ceaserShifter = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
std::string customKey;
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
        if(curLine.find("Encrypted=")!= std::string::npos){
            for(int i = 10; i < curLine.length();i++){
                encrypted += curLine[i];
            }
        }
        if(curLine.find("Method=") != std::string::npos && !modeSet){
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
            break;
        }
    }
    return true;
}

bool customInit(){

    bool startCustKey = false;
    int custKeyPointer = 0;
    std::fstream cust;
    cust.open(CONFIG_FILE_PATH, std::ios::in);

    if(cust.is_open()!=true){return false;}
    
    while(true){
        std::string curLine;
        std::getline(cust,curLine);

        if(curLine.find("a=")!= std::string::npos){
            startCustKey = true;
        }

        if(startCustKey && custKeyPointer <= 25){
            customKey += (curLine[2]);
            custKeyPointer++;
        }
        if(custKeyPointer > 25){break;}
    }
    return true;
}

std::string custom(){
    for(int i = 0; i <= encrypted.length();i++){
        char c = encrypted[i];
        int abcPos = abc.find(c);
        encrypted[i] = customKey[abcPos];
    }
    return encrypted;
}

std::string ceaser(int shift){
    
    return encrypted;
}

int main(){
    configRead();
    if(isCeaser==false&&mode==0){
        customInit();
        std::cout << custom();
    }else if(isCeaser==false&&mode==1){
        customKey = zyx;
        std::cout << custom();
    }
    return 0;
}