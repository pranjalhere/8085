#include<iostream>
#include<string>
#include"../header/Converter.h"
#include"../header/addrfun.h"
using namespace std;

string JNZ(string data1,string pc,string registers[],bool flag[]){
    if(flag[6]==false){
        pc = data1;
    }else{
        return pc;
    }
    return pc;
}