#include<iostream>
#include<string>
#include<map>
#include"../header/regisfun.h"
#include"../header/engine.h"
#include"../header/hexafun.h"
using namespace std;

void SUB(string data,string registers[],bool flag[],map<string,string>&memory){
    int len = data.length();
    if(len==1){
        char data1 = data[0];
        
            if(data1!='M'){
                if(validReg(data1)){
                int regID = (registerNum(data1));

                registers[0] = Subhex(registers[regID],registers[0],flag,true);
                }else{
                    cout<<"Error"<<endl;
                    exit(0);
                }
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
}