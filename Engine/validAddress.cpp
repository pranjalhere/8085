#include<iostream>
#include<string>
using namespace std;
bool validAddr(string data){
    bool flag;

    int len = data.length();
    for(int i=0;i<len;i++){
        if((data[i]>='0' && data[i]<='9') || (data[i]>='A' && data[i]<='F')){
            flag=true;
        }else{
           flag = false;
           break;
        }
    }
    return flag;
}