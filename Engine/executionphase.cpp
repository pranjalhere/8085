#include<iostream>
#include<string>

#include<vector>
#include<map>
#include"execution.cpp"


using namespace std;

void executionphase(string &pc,bool flag[],map<string,string>&memory,string registers[],vector<string>&commands){
      int i=0;

      while(i<commands.size()){
         int k=execution(pc,flag,memory,registers,commands[i],commands,i);
         i+=k;
      }
}