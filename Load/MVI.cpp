#include<iostream>
#include<string>
#include<map>
#include"../header/datafun.h"
#include"../header/regisfun.h"
using namespace std;
void MVI(string data1,string data2,string registers[],bool flag[],map<string,string>memory){
    int l1 = data1.length();
    int l2 = data2.length();
    if(l1==1 && l2==4){
        char data1temp=data1[0];
        if(data1=="M"){
            string address = registers[5]+registers[6];
            if(validData(data2)){
                memory[address]=data2;
            }
            else{
                cout<<"Error : Invalid value"<<endl;
                exit(0);
            }
        }
        else if(validReg(data1temp) && validData(data2)){
           
            registers[registerNum(data1temp)]=data2;
        }
        else{
            cout<<"Error Occured"<<endl;
            exit(0);
        }
    }
    else{
        cout<<"Error Occured"<<endl;
        exit(0);
    }
}