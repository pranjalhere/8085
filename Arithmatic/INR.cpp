#include<iostream>
#include<string>
#include<map>
#include"../header/regisfun.h"
#include"../header/addrfun.h"
#include"../header/hexafun.h"
using namespace std;

void INR(string data,string registers[],bool flag[],map<string,string>&memory){
    int l1 = data.length();
    if(l1==1){
        char data1 = data[0];
        if((validReg(data1))){
            if(data1!='M'){
                int registerId = (registerNum(data1));
                registers[registerId] = Addhexa(registers[registerId],"01",flag,false);
            }else{
                

                string address = "";
                address = address+registers[5]+registers[6];
                if((validAddr(address))){
                    memory[address]=Addhexa(memory[address],"01",flag,false);
                }else{
                    cout<<"Error: Generated From the INR command Invalid Address generated from HL register Pair"<<endl;
                    exit(0);
                }
            }
        }
        else{
              cout<<"Error: Generated From the INR command Invalid register"<<endl;
              exit(0);
         }
    }
    else{
        cout<<"Error: Generated From the INR command Invalid command"<<endl;
        exit(0);
    }
}