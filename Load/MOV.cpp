#include<iostream>
#include<string>
#include<map>
#include"../header/regisfun.h"
using namespace std;

void MOV (char data1,char data2,string registers[],bool flag[],map<string,string>&memory){

   if(data1=='M' && data2!='M' && validReg(data2)){
      string Address="";
      Address=(registers[5]+registers[6]);
      memory[Address]=registers[registerNum(data2)];
   }else if(data1!='M' && data2=='M' && validReg(data1)){
      string Address="";
      Address=(registers[5]+registers[6]);
      registers[registerNum(data1)]=memory[Address];
   }else if(data1!='M' && data2!='M' && validReg(data1) && validReg(data2)){
        registers[registerNum(data1)]=registers[registerNum(data2)];
   }else{
      cout<<"Error MOV"<<endl;
   }
}