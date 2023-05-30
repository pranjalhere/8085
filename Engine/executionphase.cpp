#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"execution.cpp"
using namespace std;
void executionphase(string &pc,bool flag[],map<string,string>&memory,string registers[]){
      while(memory[pc]!="HLT"){
            pc=execution(pc,flag,memory,memory[pc],registers);
      }
}
void debugg(string &pc,bool flag[],map<string,string>&memory,string registers[]){
      pc=execution(pc,flag,memory,memory[pc],registers);
}