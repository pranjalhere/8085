#include<iostream>
#include<string>
#include"../header/addrfun.h"
#include"../header/Converter.h"
using namespace std;


string JNC(string data1,string pc,string registers[],bool flag[]){
    if(flag[0]==false){
        pc=data1;
    }else{
        return pc;
    }
    return pc;
}