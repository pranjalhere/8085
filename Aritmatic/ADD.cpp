#include<iostream>
#include<string>
#include<map>

using namespace std;

void ADD(string data1,string registers[],bool flag[],map<string,string>&memory){
    int len=data1.length();

    if(len==1){
        if((validReg(data1))|| validRegpair(data1)){
            if(data1!="M"){
                int regId = (registerNum(data1));
                //regiter 0 act as as the accumulator
                registers[0]=Addhexa(registers[regId],registers[0],flag,true);
            }else{
                string address="";
                address=address+registers[5]+registers[6];
                if(address>="0000" && address<="FFFF"){
                    registers[0] = Addhexa(memory[address],registers[0],flag,true);
                }else{
                    cout<<"Error: "<<endl;
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