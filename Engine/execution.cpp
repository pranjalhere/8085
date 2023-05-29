#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"../header/load.h"
#include"../header/logical.h"
#include"../header/Arithmatic.h"
#include"../header/branch.h"
#include"../header/addrfun.h"
#include"../header/Converter.h"

using namespace std;

int  execution(string &pc,bool flag[],map<string,string>&memory,string registers[],string cmd,vector<string>&commands,int i){
    int nxt=0;
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
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }
         else if(res=="LDA"){
            string add=cmd.substr(4,4);
            LDA(add,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }
         else if(res=="LXI"){
            string data1=cmd.substr(4,1);
            string data2=cmd.substr(6,4);
            LXI(data1,data2,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }
         else if(res=="MVI"){
            string data1=cmd.substr(4,1);
            string data2=cmd.substr(6,4);
            int k = operationSize(res);
            pc = nextAddress(pc,k);
            MVI(data1,data2,registers,flag,memory);
            
         }
         else if(res=="STA"){
            string add=cmd.substr(4,4);
            STA(add,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="CMA"){
            CMA(registers,flag);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }
         else if(res=="CMP"){
            char data1 = cmd[4];
            CMP(data1,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="ADD"){
            string data1 = cmd.substr(4,1);
            ADD(data1,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="ADI"){
            string data1 = cmd.substr(4,2);
            ADI(data1,registers,flag);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="DCR"){
            string data1 = cmd.substr(4,1);
            DCR(data1,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="INR"){
             string data1 = cmd.substr(4,1);
             INR(data1,registers,flag,memory);
              int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="DCX"){
            string data1 = cmd.substr(4,1);
             DCX(data1,registers,flag);
              int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="INX"){
             string data1 = cmd.substr(4,1);
             INX(data1,registers,flag);
              int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="SUB"){
             string data1 = cmd.substr(4,1);
             SUB(data1,registers,flag,memory);
              int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="SUI"){
            string data1 = cmd.substr(4,2);
            SUI(data1,registers,flag);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }
         else if(res=="DAD"){
            string data1 = cmd.substr(4,1);
            DAD(data1,registers,flag);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
         }else if(res=="JMP"){
            string data1 = cmd.substr(4,4);
            pc=JMP(data1,registers,flag);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
        }
        else if(res=="JNC"){
            string data1 = cmd.substr(4,4);
            pc=JNC(data1,pc,registers,flag);
            
        }
         else if(res=="JNZ"){
            string data1 = cmd.substr(4,4);
            pc=JNZ(data1,pc,registers,flag);
        
        }
     }
     else if(k==4){
        if(res=="LHLD"){
            string add=cmd.substr(5,4);
            LHLD(add,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
        }
        else if(res=="SHLD"){
            string add=cmd.substr(5,4);
            SHLD(add,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
        }else if(res=="STAX"){
            string data1 = cmd.substr(5,1);
            STAX(data1,registers,flag,memory);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
        }else if(res=="XCHG"){
            XCHG(registers,flag);
             int k = operationSize(res);
             pc = nextAddress(pc,k);
        }
     }else if(k==2){
        if(res=="JC"){
            string data1 = cmd.substr(3,4);
            string rs=JC(data1,pc,registers,flag);
            if(rs==pc){
                int k = operationSize(res);
                pc = nextAddress(pc,k);
                return 1;
            }
            else{
                int arr[4]={0,0,0,0};
                int arr1[4]={0,0,0,0};
                Converter_h_to_D(rs,arr);
                Converter_h_to_D(pc,arr1);
                int one= Arraytoint(arr);
                int two=Arraytoint(arr1);
                int dif = one-two;
                if(dif>0){
                    while(dif!=0){
                    for(int j=i;j<commands.size();j++){
                        string temp="";
                        for(int l=0;l<commands[j].size();l++){
                             if(commands[j][l]!=' '){
                                    temp+= commands[j][l];
                                }else{
                                    break;
                             }
                        }
                        int op = operationSize(temp);
                        if(dif>0){
                        //jaise yhn pc update ho rha h na aise hi
                        pc = nextAddress(pc,op);
                        dif-=op;
                        nxt++;
                        }
                        else {
                            break;
                        }
                    }
                  }
                }
                else{
                     while(dif!=0){
                    for(int j=i;j<commands.size();j++){
                        string temp="";
                        for(int l=0;l<commands[j].size();l++){
                             if(commands[j][l]!=' '){
                                    temp+= commands[j][l];
                                }else{
                                    break;
                             }
                        }
                        int op = operationSize(temp);
                            if(dif<0){
                                //pc = nextAddress(pc,op);
                                //jaise yeh pc update ho rha h na waise hi ek prevadress ka function bnega jo pc ko prev krega
                                dif+=op;
                                nxt--;
                            }
                            else 
                            {
                                break;
                            }
                    }
                  }
                
                }
            }
            return nxt;    
        }
        else if(res=="JZ"){
            string data1 = cmd.substr(3,4);
            pc=JZ(data1,pc,registers,flag);
            
        }
     }
     return 1;
}