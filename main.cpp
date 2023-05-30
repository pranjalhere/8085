#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include"./header/engine.h"
#include"./header/addrfun.h"
using namespace std;
//Parity--->2
//Sign flag--->7
//carry-->0
//zero-->6
class MICRO8085{
    map<string,string>memory;
    map<string,string>debugmemory;
    vector<string>Line;
    string registers[7];
    bool flag[8];
    string pc;
    string oldpc;
    public:
    MICRO8085(){
       
        for(int i=0;i<8;i++){
            flag[i]=false;
        }
        for(int i=0;i<7;i++){
           registers[i]="NULL";
        }
    }
    void start(){
        fstream file;
        file.open("input.txt");
        string templine;
        while(!file.eof()){

           getline(file,templine);
          
            Line.push_back(templine);
        }
        cout<<"Enter the starting Address"<<endl;
        cin>>pc;
        oldpc=pc;
        string map_pc=pc;
        for(int i=0;i<Line.size();i++){
            if(i==0){
                memory[pc]=Line[i];
                debugmemory[pc]=Line[i];
            }
            if(i!=0){
                memory[map_pc]=Line[i];
                debugmemory[map_pc]=Line[i];
            }
             string temp="";
            for(int j=0;j<Line[i].size();j++){
                 if(Line[i][j]!=' '){
                    temp+=Line[i][j];
                 }else{
                    break;
                 }
            }

            int k = operationSize(temp);
            map_pc=nextAddress(map_pc,k);
        }
    }
     void check(){
        if(Line[Line.size()-1]!="HLT"){
            cout<<"\n";
            cout<<"\n";
            cout<<"HLT not found"<<endl;
            exit(0);
        }
    }
    void set(){
        string m="";
        string data="";
        cout<<"\n";
        cout<<"\n";
        cout<<"Enter the memory location"<<endl;
        cin>>m;
        cout<<"\n";
        cout<<"\n";
        cout<<"Enter the data"<<endl;
        cin>>data;
        memory[m]=data;
        debugmemory[m]=data;
    }
    void print(){
        map<string,string>::iterator it = memory.begin();
        while(it!=memory.end()){
            cout<<it->first<<" : "<<it->second<<endl;
            it++;
        } 
    }
    void printspec(){
        string loc="";
        cout<<"\n";
        cout<<"\n";
        cout<<"Enter the memory location"<<endl;
        cin>>loc;
        cout<<"\n";
        cout<<"\n";
        cout<<loc<<" : "<<memory[loc]<<endl;
    }
    void run()
    {
        executionphase(pc,flag,memory,registers);
    }
    void debug(){
        for(int i=0;i<8;i++){
            flag[i]=false;
        }
        for(int i=0;i<7;i++){
           registers[i]="NULL";
        }
        int k=0;
        while(Line[k]!="HLT"){
            int c;
            cout<<"\n";
            cout<<"\n";
            cout<<"Press [1] for one step down and [0] for exit debugger"<<endl;
             cin>>c;
            if(c==1){
            debugg(oldpc,flag,debugmemory,registers);
            cout<<"\n";
            cout<<"\n";
            cout<<"Registers:"<<endl;
            for (int i = 0; i < 7; i++)
            {
                cout<<registers[i]<<" ";
            }
            cout<<"\n";
            cout<<"\n";
            cout<<"Flag Reegisters:"<<endl;
             for (int i = 0; i < 8; i++)
            {
                cout<<flag[i]<<" ";
            }
            map<string,string>::iterator it = debugmemory.begin();
            cout<<"\n";
            cout<<"\n";
            cout<<"Address : Data"<<endl;
            while(it!=debugmemory.end()){
                cout<<it->first<<" : "<<it->second<<endl;
                it++;
             } 
            }
            else if(c==0){
                break;
            }
            else{
                cout<<"\n";
                cout<<"\n";
                cout<<"Wrong input"<<endl;
            }
            k++;
        }
        exit(0);
    }   
};

int main(){

    MICRO8085 process;
    process.start();
    while(true){
        char ch;
        cout<<"\n";
        cout<<"\n";
        cout<<"Do you want to set memory?"<<"\n"<<"Press [Y] for yes ans [N] for no"<<endl;
        cin>>ch;
        if(ch=='Y'){
            process.set();
        }
        else if(ch=='N'){
            break;
        }
        else{
            cout<<"\n";
            cout<<"\n";
            cout<<"Wrong input"<<endl;
        }
        }
    while (true)
    {
        int c;
        cout<<"\n";
        cout<<"\n";
        cout<<"Enter your choice:"<<endl;
        cout<<"[1] for print whole memory"<<endl;
        cout<<"[2] for execute your code"<<endl;
        cout<<"[3] for see specific memory"<<endl;
        cout<<"[4] for debug your code"<<endl;
        cout<<"[5] for exit"<<endl;
        cin>>c;
        if(c==1){
            cout<<"\n";
            cout<<"\n";
            cout<<"Address : Data"<<endl;
            process.print();
        }
        else if(c==2){
            process.check();
            process.run();
            cout<<"\n";
            cout<<"\n";
            cout<<"NO SYANTAX ERROR"<<"\n"<<"Code Executed"<<endl;
        }
        else if(c==3){
            process.printspec();
        }
        else if(c==4){
            process.check();
            process.debug();
        }
        else if(c==5){
            break;
        }
        else{
            cout<<"\n";
            cout<<"\n";
            cout<<"Wrong Input.Enter it again"<<endl;
        }
    }
}