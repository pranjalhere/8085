#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

#include"./header/engine.h"

using namespace std;

class vansh8085{
    map<string,string>memory;
    string registers[7];
    
    vector<string>Line;
    bool flag[8];
    string pc;
    public:
    vansh8085(){
       registers[1]="0A";
       registers[2]="23";
       registers[5]="0B";
       registers[6]="C2";
        
       
        for(int i=0;i<8;i++){
            flag[i]=false;
        }
        pc="";
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

        cout<<registers[5];
        cout<<registers[6];
       
        
    }
    void check(){
        if(Line[Line.size()-1]!="HLT"){
            cout<<"HLT not found"<<endl;
            exit(0);
        }
    }

    void run()
    {
        executionphase(pc,flag,memory,registers,Line);
    }

    
};

int main(){
    vansh8085 let;
    let.input();
    let.run();
   // let.check();
    let.print();
}