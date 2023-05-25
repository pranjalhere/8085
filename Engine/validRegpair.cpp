#include<iostream>
#include<string>
using namespace std;
bool validRegpair(string res){
    if(res=="B" || res=="D" || res=="H" || res=="M"){
        return true;
    }else{
        return false;
    }
}