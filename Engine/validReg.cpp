#include<iostream>
#include<string>

using namespace std;

bool validReg(char reg){
    if(reg=='A' || reg=='B' || reg=='C' || reg=='D' || reg=='E' || reg=='H' || reg=='L'){
         return true;
    }else{
        return false;
    }
}
