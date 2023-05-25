#include<iostream>
#include<string>
#include<map>
#include"engine.h"
using namespace std;
void DCX(string arg,string registers[],bool flag[]){

	int length = arg.length();
	if(length == 1){
	
		if((validReg(arg))){
			
			int registerID = registerNum(arg);
			if(registerID == 1 || registerID == 3 || registerID == 5){
			
				string data16bit = "";
				string temporary = "";
				string s1 = "";
				string s2 = "";
				if((validData(registers[registerID])) == true && (validData(registers[registerID+1])) == true){
					
					data16bit = data16bit + registers[registerID] + registers[registerID + 1];
					temporary = (hexSub16bit(data16bit,"0001",flag,false));
					 s1 = s1 + temporary[0] + temporary[1];		
					 s2 = s2 +temporary[2] + temporary[3];
					registers[registerID] = s1;
					registers[registerID+1] = s2;
				}
				else{
					cout<<"Error"<<endl;
					exit(0);
					
				}
			}
			else{
				cout<<"Error"<<endl;
				exit(0);
			
			}
		}
		else{
			cout<<"Error"<<endl;
			exit(0);
		
		}
	}
	else{
		cout<<"Error"<<endl;
		exit(0);
		
	}
}