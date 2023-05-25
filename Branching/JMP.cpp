#include<iostream>
#include<string>
#include"engine.h"
using namespace std;

string JMP(string data1,string registers[],bool flag[]){
    if(validAddress(data1)){
        return data1;
    }else{
        cout<<"Error In JMP instruction"<<endl;
        exit(0);
    }
}