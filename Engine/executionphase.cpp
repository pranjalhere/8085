#include<iostream>
#include<string>

#include<vector>
#include<map>
#include"execution.cpp"


using namespace std;

void executionphase(string pc,bool flag[],map<string,string>&memory,string registers[],vector<string>&commands){
    
       for(int i=0;i<commands.size()-1;i++){
           execution(pc,flag,memory,registers,commands[i]);
       }
}