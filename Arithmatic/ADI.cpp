#include<iostream>
#include<string>
#include<map>
#include"engine.h"
using namespace std;

void ADI(string data1,string registers[],bool flag[]){

    int len = data1.length();
    if(len==2){
        if((validData(data1))){
            //registers[0] act as a accumulator hers
            registers[0] = Addhexa(data1,registers[0],flag,true);
        }
        else{
            cout<<"Error"<<endl;
            exit(0);
        }
    }else{
        cout<<"Error"<<endl;
    }
}
int main(){
    cout<<"nem";
}
