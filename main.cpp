#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

#include"./header/engine.h"
#include"./header/addrfun.h"

using namespace std;

class MICRO8085{
    map<string,string>memory;
    string registers[7];
    
    vector<string>Line;
    bool flag[8];
    string pc;
    public:
    MICRO8085(){
       
        for(int i=0;i<8;i++){
            flag[i]=false;
        }
        for(int i=0;i<7;i++){
           registers[i]="NULL";
        }
        memory["2050"]="0F";
        memory["2051"]="02";
    }
    void start(){
        cout<<"Enter the starting Address"<<endl;
        cin>>pc;
    }
    void input(){
        fstream file;
        file.open("input.txt");
        string templine;
        while(!file.eof()){

           getline(file,templine);
          
            Line.push_back(templine);
           
        }
    }
    void print(){
        // for(int i=0;i<Line.size();i++){
        //     cout<<Line[i]<<endl;
        // }
            
        map<string,string>::iterator it = memory.begin();
        while(it!=memory.end()){
            cout<<it->first<<" : "<<it->second<<endl;
            it++;
        }
       
    //    cout<<registers[0]<<endl;
    //    cout<<registers[1]<<endl;
    //    cout<<pc<<endl;

    cout<<memory["3050"]<<endl;
        
    }
    void check(){
        if(Line[Line.size()-1]!="HLT"){
            cout<<"HLT not found"<<endl;
            exit(0);
        }
    }

    void run()
    {
        string map_pc=pc;
        for(int i=0;i<Line.size();i++){
            if(i==0){
                memory[pc]=Line[i];
            }
            if(i!=0){
                memory[map_pc]=Line[i];
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
        executionphase(pc,flag,memory,registers);
    }

    
};

int main(){

    MICRO8085 let;
    let.start();
    
    let.input();
    let.run();
    let.print();
}