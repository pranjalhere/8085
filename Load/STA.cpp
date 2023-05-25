#include<iostream>
#include<map>
#include<string>
#include"engine.h"
using namespace std;
void STA(string data1,string registers[],bool flag[],map<string,string>&memory){
      int l2 = data1.length();
      if(l2==4){
          if(validAddress(data1)){
              memory[data1]=registers[0];
          }else{
              cout<<"Error"<<endl;
              exit(0);
          }
      }else{
          cout<<"Error"<<endl;
          exit(0);
      }
}