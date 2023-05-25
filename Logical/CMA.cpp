#include<iostream>
#include<string>
#include"engine.h"
#include<map>
using namespace std;
void CMA(string registers[],bool flag[]){
    string comp = complement(registers[0]);
    registers[0]=complement;
    if(registers[0]=="00"){
        flag[6]=true;
        flag[2]=true;
    }else{
        string kemp = registers[0];
        int array[2];
        Converter_h_to_D.cpp(temp,array);
        int value = array[1]*16+array[0];
        bitset<8>dataInBinary(value);
        int parity = dataInBinary.count();

        if(parity%2==0 && parity!=0){
            flag[2] = true;
        }else{
            flags[2]=false;
        }
    }
}