#include<iostream>
#include<string>
#include"../header/addrfun.h"
#include"../header/Converter.h"
using namespace std;


string JZ(string data1,string pc,string registers[],bool flag[]){
    if(flag[6]==true){
        pc=data1;
    }else{
       return pc;
    }
    return pc;
}