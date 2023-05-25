#include<iostream>
#include<string>
#include<map>
#include"engine.h"
using namespace std;

void INR(string data1,string registers[],bool flag[],map<string,string>&memory){
    int l1 = data1.length();
    if(l1==1){
        if((validReg(data1))){
            // perform decrement on ther value stored in register
            if(data1!="M"){
                int registerId = registerNum(data1);
                registers[registerId] = Subhex(registers[registerId],"01",flag,false);
            }else{
                // perform decrement on the memoery which is pointed by hl register pairs

                string address = "";
                address = address+registers[5]+registers[6];
                if((validAddress(address))){
                    memory[address]=Subhex(memory[address],"01",flag,false);
                }else{
                    cout<<"Error: "<<data1<<"address is correct"<<endl;
                    exit(0);
                }
            }
        }
        else{
              cout<<"Error: "<<data1<<"address is correct"<<endl;
              exit(0);
         }
    }
    else{
        cout<<"Error: "<<data1<<"address is correct"<<endl;
        exit(0);
    }
}