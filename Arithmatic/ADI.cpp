#include<iostream>
#include<string>
#include<map>
#include"../header/datafun.h"
#include"../header/regisfun.h"
#include"../header/engine.h"
using namespace std;

void ADI(string data1,string registers[],bool flag[]){

    int len = data1.length();
    if(len==2){  
              //registers[0] act as a accumulator hers
              if((data1[0]>='0' && data1[0]<='9')||(data1[0]>='A' && data1[0]<='F')){
                if((data1[1]>='0' && data1[1]<='9')||(data1[1]>='A' && data1[1]<='F')){
                  registers[0] = Addhexa(data1,registers[0],flag,true);
                }
              }
    }else{
        cout<<"Error"<<endl;
    }
}