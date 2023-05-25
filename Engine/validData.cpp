#include<iostream>
#include<string>
using namespace std;
bool ishexadecimal(char a){
    if((a>='0' && a<='9')||(a>='A' && a<='F')){
        return true;
    }else{
        return false;
    }
}
bool validData(string res){
    int len = res.length();
    if(len==1 && ishexadecimal(res[0]) && ishexadecimal(res[1])){
        return true;
    }else{
        return false;
    }
}