#include<iostream>
#include<string>
#include<map>
#include"../header/regisfun.h" 
using namespace std;

void CMP(char data1,string registers[],bool flag[],map<string,string>&memory){


  
        if(data1=='M'){
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
}
