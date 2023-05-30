#include<iostream>
#include<string>
#include<map>
#include"../header/addrfun.h"
#include"../header/regisfun.h"
using namespace std;
void LXI(string data1,string data2,string registers[],bool flag[],map<string,string>&memory){
    int len1 = data1.length();
    int len2 = data2.length();
    char datatemp=data1[0];
    if(len1==1 && len2==4){
            if(validReg(datatemp) && validAddr(data2)){
                string part1 = "";
                string part2 = "";
                for(int i=0;i<2;i++){
                    part1+=data2[i];
                    part2+=data2[i+2];
                }

                registers[registerNum(datatemp)]=part1;
                registers[registerNum(datatemp)+1]=part2;
            }else{
                cout<<"Error : Generated from the LXI command Either the register or address are invalid"<<endl;
                exit(0);
            }
        }
    else{
        cout<<"Error : Generated from the LXI command Either the register or address are invalid"<<endl;
        exit(0);
    }
}