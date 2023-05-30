#include<iostream>
#include<string>
#include<map>
#include"../header/addrfun.h"
using namespace std;
void LHLD(string data1,string registers[],bool flag[],map<string,string>&memory){
    int len = data1.length();
    if(len==4){
        if(validAddr(data1) && validAddr(increaseAddress(data1))){
            registers[6] = memory[data1];
            registers[5] = memory[increaseAddress(data1)];
        }else{
            cout<<"Error :Generated from the LHLD command Invalid Address"<<endl;
            exit(0);
        }
    }else{
        cout<<"Error: Generated from the LHLD command Invalid Address"<<endl;
        exit(0);
    }
}