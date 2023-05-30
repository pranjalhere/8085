#include<iostream>
#include<string>
#include"../header/Converter.h"
using namespace std;

string Addhexa(string data1,string data2,bool flag[],bool carry){
    string res = "";
    int variable;
    int op1[2]={0};
    int op2[2]={0};
    int calu[2];

    Converter_h_to_D(data1,op1);
    Converter_h_to_D(data2,op2);
    
    calu[1] = op1[1]+op2[1];
    
    if(calu[1]>=16){
            calu[1] = calu[1]%16;
            op1[0]++;
            flag[4]=true;
    }
    
    calu[0] = op1[0]+op2[0];

    if(calu[0]>=16){
        calu[0] = calu[0]%16;
        if(carry==true){
            flag[0]=true;
        }
    }

    variable = calu[0]%16+calu[1];
    bitset<8>dataInbinary(variable);

    int parity = dataInbinary.count();

    if(parity%2==0 && parity!=0){
        flag[2]=true;
    }else{
        flag[2]=false;
    }

    flag[7]=dataInbinary[7];

    if(parity==0){
       flag[6]=true;
    }else{
        flag[6]=false;
    }
    for(int i=1;i>=0;i--){
           if(calu[i]>=0 && calu[i]<=9){
               res=char('0'+calu[i])+res;
           }else if(calu[i]>=10 && calu[i]<=15){
               res=(char)('A'+(calu[i]-10))+res;
           }
    }
    return res;
}