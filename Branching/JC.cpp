#include<iostream>
#include<string>
#include"../header/addrfun.h"
using namespace std;
string JC(string data1,string pc,string registers[],bool flag[]){
    string ans="";
    if(flag[0]==true){
        ans=data1;
    }else{
            ans=pc;
    }
    return ans;
}