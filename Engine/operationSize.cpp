#include<iostream>
#include<string>
using namespace std;

int ooperationSize(string data){
    if(data=="LDA"){
        return 3;
    }
    else if(data=="MOV"){
        return 1;
    }
    else if(data=="MVI"){
        return 2;
    }
    else if(data=="LXI"){
        return 3;
    }else if(data=="STA"){
        return 3;
    }else if(data=="LHLD"){
        return 3;
    }else if(data=="SHLD"){
        return 3;
    }else if(data=="STAX"){
        return 3;
    }else if(data=="XCHG"){
        return 1;
    }else if(data=="ADD"){
        return 1;
    }else if(data=="ADI"){
        return 2;
    }else if(data=="SUB"){
        return 1;
    }else if(data=="INR"){
        return 1;
    }else if(data=="DCR"){
        return 1;
    }else if(data=="DCX"){
        return 1;
    }else if(data=="INX"){
        return 1;
    }else if(data=="DAD"){
        return 1;
    }else if(data=="SUI"){
        return 2;
    }else if(data=="CMA"){
        return 1;
    }else if(data=="CMP"){
        return 1;
    }else if(data=="JMP"){
        return 3;
    }else if(data=="JC"){
        return 3;
    }else if(data=="JZ"){
        return 3;
    }else if(data=="JNC"){
        return 3;
    }else if(data=="JNZ"){
        return 3;
    }
}