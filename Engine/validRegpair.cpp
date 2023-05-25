#include<iostream>
#include<string>
using namespace std;
bool validRegpair(char res){
    if(res=='B' || res=='D' || res=='H' || res=='L'){
        return true;
    }else{
        return false;
    }
}