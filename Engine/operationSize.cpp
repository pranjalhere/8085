#include<iostream>
#include<string>
using namespace std;

int operationSize(string data){
    int k;
    if(data=="LDA"){
        k= 3;
    }
    else if(data=="MOV"){
        k= 1;
    }
    else if(data=="MVI"){
        k= 2;
    }
    else if(data=="LXI"){
        k= 3;
    }else if(data=="STA"){
        k= 3;
    }else if(data=="LHLD"){
        k= 3;
    }else if(data=="SHLD"){
        k= 3;
    }else if(data=="STAX"){
        k= 3;
    }else if(data=="XCHG"){
        k= 1;
    }else if(data=="ADD"){
        k= 1;
    }else if(data=="ADI"){
        k= 2;
    }else if(data=="SUB"){
        k= 1;
    }else if(data=="INR"){
        k= 1;
    }else if(data=="DCR"){
        k= 1;
    }else if(data=="DCX"){
        k= 1;
    }else if(data=="INX"){
        k= 1;
    }else if(data=="DAD"){
        k= 1;
    }else if(data=="SUI"){
        k= 2;
    }else if(data=="CMA"){
        k= 1;
    }else if(data=="CMP"){
        k= 1;
    }else if(data=="JMP"){
        k= 3;
    }else if(data=="JC"){
        k= 3;
    }else if(data=="JZ"){
        k= 3;
    }else if(data=="JNC"){
        k= 3;
    }else if(data=="JNZ"){
        k= 3;
    }
    return k;
}