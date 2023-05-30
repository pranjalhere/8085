#include<iostream>
#include<string>
#include<map>
#include"../header/regisfun.h"
#include"../header/hexafun.h"

using namespace std;

void ADD(string data,string registers[],bool flag[],map<string,string>&memory){
    int len=data.length();

    if(len==1){
        char data1 = data[0];
        if((validReg(data1)) || validRegpair(data1)){
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
                    cout<<"Error: Generated from the ADD command Invalid Address given in HL pair"<<endl;
                    exit(0);
                }
            }
        }else{
            cout<<"Error: Generated from ADD data with add command is not appropiates"<<endl;
            exit(0);
        }
    }else{
        cout<<"Error: Generated From ADD Command"<<endl;
        exit(0);
    }
}