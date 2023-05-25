#include<iostream>
#include<string>
#include<map>
#include"../header/regisfun.h"
#include"../header/addrfun.h"

using namespace std;
void STAX(string data1,string registers[],bool flag[],map<string,string>&memory){
    char ch = data1[0];
    
     if(validRegpair(ch)){
            string address="";
            int index=registerNum(ch);
            address+=registers[index]+registers[index+1];
            if(validAddr(address)){
                memory[address]=registers[0];
            }else{
                cout<<"Error"<<endl;
                exit(0);
            }
        }else{
            cout<<"Error"<<endl;
            exit(0);
        }
}