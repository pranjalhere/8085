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
       
        for(int i=0;i<8;i++){
            flag[i]=false;
        }
        flag[0]=true;
        pc="3000";
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

        cout<<registers[0]<<endl;
        cout<<pc<<endl;
        
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