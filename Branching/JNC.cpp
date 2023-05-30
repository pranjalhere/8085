#include<iostream>
#include<string>
#include"../header/addrfun.h"
#include"../header/Converter.h"
using namespace std;


string JNC(string data1,string pc,string registers[],bool flag[]){
    if(flag[0]==false){
        if(validAddr(data1)){
            pc=data1;
        }else{
            cout<<"Error :Generated from the  JNC command Invalid Jump address"<<endl;
        }
        
    }else{
        return pc;
    }
    return pc;
}