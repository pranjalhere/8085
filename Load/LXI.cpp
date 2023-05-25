#include<iostream>
#include<string>
#include<map>
#include "engine.h"
using namespace std;
void LXI(string data1,string data2,string registers[],bool flag[],map<string,string>&memory){
    int len1 = data1.length();
    int len2 = data2.length();

    if(len1==1 && len2==4){
        if(data1=="M"){
            if(validAddress(data2)){
                string part1="",part2="";
                for(int i=0;i<2;i++){
                    part1+=data2[i];
                    part2+=data2[i+2];
                }

                registers[5]=part1;
                registers[6]=part2;

            }else{
                cout<<"Error"<<endl;
                exit(0);
            }
        }else{
            if(validRegpair(data1) && validAddress(data2)){
                string part1 = "";
                string part2 = "";
                for(int i=0;i<2;i++){
                    part1+=data2[i];
                    part2 = data2[i+2];
                }

                registers[registerNum(data1)]=part1;
                registers[registerNum(data1)+1]=part2;
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