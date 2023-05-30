#include<iostream>
#include<string>
#include"../header/addrfun.h"
using namespace std;
string JC(string data1,string pc,string registers[],bool flag[]){
    string ans="";
    if(flag[0]==true){
        if(validAddr(data1)){
          ans=data1;
        }else{
            cout<<"Error: Generated from the JC commnad Invalid jump address"<<endl;
        }
        
    }else{
            ans=pc;
    }
    return ans;
}