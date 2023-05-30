#include<iostream>
#include<string>
#include<map>
#include"../header/engine.h"
#include"../header/addrfun.h"
#include"../header/hexafun.h"
using namespace std;

void DCR(string data,string registers[],bool flag[],map<string,string>&memory){
    int l1 = data.length();
    if(l1==1){
        char data1 = data[0];
        if((validReg(data1))){
           
            if(data1!='M'){
                int registerId = registerNum(data1);
                registers[registerId] = Subhex(registers[registerId],"01",flag,false);
            }else{
                string address = "";
                address = address+registers[5]+registers[6];
                if((validAddr(address))){
                    memory[address]=Subhex(memory[address],"01",flag,false);
                }else{
                    cout<<"Error: Generated from DCR command Trying to decrement Invalid memory data "<<endl;
                    exit(0);
                }
            }
        }
        else{
              cout<<"Error: Generated from DCR command Trying to decrement Invalid Register data"<<endl;
              exit(0);
        }
    }
    else{
        cout<<"Error: Generated from the DCR command"<<endl;
        exit(0);
    }
}