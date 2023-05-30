#include<iostream>
#include<string>
#include"../header/addrfun.h"
#include"../header/Converter.h"
using namespace std;


string JZ(string data1,string pc,string registers[],bool flag[]){
    if(flag[6]==true){
        if(validAddr(data1)){
              pc=data1;
        }else{
            cout<<"Error : Generated from the JZ command Invalid jump address"<<endl;
        }
       
    }else{
       return pc;
    }
    return pc;
}