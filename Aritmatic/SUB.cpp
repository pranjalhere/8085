#include<iostream>
#include<string>
#include<map>
#include"engine.h"
using namespace std;

void SUB(string data1,string registers[],bool flag[],map<string,string>&memory){
    int len = data1.length();
    if(len==1){
        if((validReg(data1))){
            if(data1!="M"){
                int regID = (registerNum(data1));

                registers[0] = Subhex(registers[regID],registers[0],flag,true);
            }else{
                string address = "";
                address = address+registers[5]+registers[6];
                if(address>="0000" && address<="FFFF"){
                    registers[0] = Subhex(memory[address],registers[0],flag,true);
                }else{
                    cout<<"Error"<<endl;
                    exit(0);
                }
            }
        }else{
            cout<<"Error"<<endl;
            exit(0);
        }
    }else{
        cout<<"Error"<<endl;
        exit(0);
    }

}