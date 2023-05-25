#include<iostream>
#include<string>
#include"engine.h"
using namespace std;


string JC(string data1,string pc,string registers[],bool flag[]){
    if(flag[0]==true){
        return data1;
    }else{
        string res="";

        int value[4];
        int returnvalue[]={0,0,0,3};
        int carry=0;
        
        Converter_h_to_D(pc,value);

        for(int i=3;i>=0;i--){
            int resvalue = value[i]+returnvalue[i]+carry;
            carry=resvalue/16;
            resvalue%=16;

            if(resvalue>=0 && resvalue<=9){
                res=(char)('0'+value)+res;
            }else{
                res=(char)('A'+(value-10))+res;
            }
        }
        if(validAddress(res)){
            return res;
        }else{
            cout<<"Error In JC Instruction"<<endl;
            exit(0);
        }

    }
}