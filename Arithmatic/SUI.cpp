#include<iostream>
#include<string>
#include"../header/regisfun.h"
#include"../header/hexafun.h"
#include"../header/datafun.h"
using namespace std;

void SUI(string data1,string registers[],bool flag[]){
    int len = data1.length();
    if(len==2){
        if((validData(data1))){
            registers[0] = Subhex(data1,registers[0],flag,true);
        }else{
        cout<<"Error Invalid data"<<endl;
        exit(0);
         }
    }else{
        cout<<"Error"<<endl;
    }
}