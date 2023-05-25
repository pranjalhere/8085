#include<iostream>
#include<map>
#include<string>
#include"../header/regisfun.h"
#include"../header/addrfun.h"
using namespace std;
void SHLD(string data1,string registers[],bool flag[],map<string,string>&memory){
    int l1 = data1.length();
    if(l1==4 && validAddr(data1) && registers[5]!="" && registers[6]!=""){
        memory[data1]=registers[6];
        memory[increaseAddress(data1)]=registers[5];
    }else{
        cout<<"Error SHLD"<<endl;
    }
}