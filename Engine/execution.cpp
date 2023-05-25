#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"../header/load.h"
#include"../header/logical.h"
using namespace std;

void execution(string pc,bool flag[],map<string,string>&memory,string registers[],string cmd){
     string res="";
     for(int i=0;i<cmd.size();i++){
         if(cmd[i]!=' '){
             res+=cmd[i];
         }else{
             break;
         }
     }

     int k = res.size();

     if(k==3){
         if(res=="MOV"){
             char data1=cmd[4];
             char data2=cmd[6];
             MOV(data1,data2,registers,flag,memory);
         }
         else if(res=="LDA"){
            string add=cmd.substr(4,4);
            LDA(add,registers,flag,memory);
         }
         else if(res=="LXI"){
            string data1=cmd.substr(4,1);
            string data2=cmd.substr(6,4);
            LXI(data1,data2,registers,flag,memory);
         }
         else if(res=="MVI"){
            string data1=cmd.substr(4,1);
            string data2=cmd.substr(6,4);
            MVI(data1,data2,registers,flag,memory);
         }
         else if(res=="STA"){
            string add=cmd.substr(4,4);
            STA(add,registers,flag,memory);
         }else if(res=="CMA"){
            CMA(registers,flag);
         }
         else if(res=="CMP"){
            char data1 = cmd[4];
            CMP(data1,registers,flag,memory);
         }
     }
     else if(k==4){
        if(res=="LHLD"){
            string add=cmd.substr(5,4);
            LHLD(add,registers,flag,memory);
        }
        else if(res=="SHLD"){
            string add=cmd.substr(5,4);
            SHLD(add,registers,flag,memory);
        }
     }
     
}