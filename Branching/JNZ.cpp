#include<iostream>
#include<string>
#include"../header/Converter.h"
#include"../header/addrfun.h"
using namespace std;

string JNZ(string data1,string pc,string registers[],bool flag[]){
    if(flag[6]==false){
        if(validAddr(data1)){
           pc = data1;
        }else{
            cout<<"Error : Generated from the JNZ command Invalid jump address"<<endl;
        }
        
    }else{
        return pc;
    }
    return pc;
}