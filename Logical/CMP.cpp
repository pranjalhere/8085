#include<iostream>
#include<string>
#include<map>
#include"engine.h"

using namespace std;

void CMP(string data1,string registers[],bool flag[],map<string,string>&memory){

    int len = data1.length();
    if(len==1){
        if(data1=="M"){
            string address = registers[5]+registers[6];
            if(registers[0]<memory[address]){
                flag[0]=true;
            }
            else if(registers[0]==memory[address]){
                    flag[6]=true;
            }else{
                    flag[0]=false;
                    flag[6]=false;
            }
            
        }else if(validReg(data1)){
            int index = registerNum(data1);

            if(registers[0]<registers[index]){
                flag[0]=true;
            }else if(registers[0]==registers[index]){
                flag[6]=true;
            }else{
                flag[0]=false;
                flag[6]=false;
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