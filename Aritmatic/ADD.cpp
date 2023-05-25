#include<iostream>
#include<string>
#include<map>
#include"../header/regisfun.h"
using namespace std;

void ADD(char data1,string registers[],bool flag[],map<string,string>&memory){
    if((validReg(data1))|| validRegpair(data1)){
            if(data1!='M'){
                
                int regId = (registerNum(data1));
                //regiter 0 act as as the accumulator
                registers[0]=Addhexa(registers[regId],registers[0],flag,true);
            }else{
                
                string address="";
                address=address+registers[5]+registers[6];
                if(address>="0000" && address<="FFFF"){
                    registers[0] = Addhexa(memory[address],registers[0],flag,true);
                }else{
                    cout<<"Error: "<<endl;
                    exit(0);
                }
            }
        }else{
            cout<<"Error"<<endl;
            exit(0);
        }
}
