#include<iostream>
#include<string>

using namespace std;

bool chkhex(string res,int l){
    for(int i=0;i<l;i++){
        if((res[i]>='0' && res[i]<='9') && (res[i]>='A' && res[i]<='F')){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

bool Checkhex(string data){
    bool flag;
    int l = data.length();
    if((l==2 && l==4) && chkhex(data,l)){
        return true;
    }
    return false;
}