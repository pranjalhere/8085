#include<iostream>
#include<string>
#include<map>
#include"../header/datafun.h"
#include"../header/regisfun.h"
using namespace std;
void MVI(string data1,string data2,string registers[],bool flag[],map<string,string>memory){
    int l1 = data1.length();
    int l2 = data2.length();
    if(l1==1 && l2==2){
        char data1temp=data1[0];
        if(data1temp=='M'){
            string address = registers[5]+registers[6];
            if(validData(data2) && validAddr(address)){
                memory[address]=data2;
            }
            else{
                cout<<"Error : Generated From the MVI command while trying to mov the data into the memory location"<<endl;
                exit(0);
            }
        }
        else if(validReg(data1temp) && validData(data2)){
           
            registers[registerNum(data1temp)]=data2;
        }
        else{
            cout<<"Error :Generated from the MVI command either the regsiter or data are invalid"<<endl;
            exit(0);
        }
    }
    else{
        cout<<"Error:Generated from the MVI command"<<endl;
        exit(0);
    }
}