#include<iostream>
#include<string>
#include"engine.h"
using namespace std;

void XCHG(string registers[],bool flag){
    string temp = registers[3];
    registers[3]=registers[5];
    registers[5]=temp;
    temp=registers[4];
    registers[4]=registers[6];
    registers[6]=temp;
}