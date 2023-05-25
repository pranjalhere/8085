#include<iostream>
#include<string>
#include<map>
#include"engine.h"
using namespace std;
void STAX(string data1,string registers[],bool flag[],map<string,string>&memory){
    int len = data1.length();
    if(len==1){
        if(validRegpair(data1)){
            string address="";
            int index=registerNum(data1);
            address+=registers[index]+registers[index+1];
            if(validAddress(address)){
                memory[address]=registers[0];
            }else{
                cout<<"Error"<<endl;
                exit(0);
            }
        }else{
            cout<<"Error"<<endl;
            exit(0);
        }
    }else{
        cout<<"Error"<<endl;
        exit(0);
    }
}