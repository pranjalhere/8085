#include<iostream>
#include<map>
#include<string>
#include"../header/addrfun.h"
using namespace std;
void LDA(string data1,string registers[],bool flag[],map<string,string>&memory){
      int l1 = data1.length();
      if(l1==4){
          if(validAddr(data1)){
              registers[0]=memory[data1];
          }else{
              cout<<"Error LDA"<<endl;
              exit(0);
          }
      }else{
          cout<<"Error LDA"<<endl;
          exit(0);
      }
}