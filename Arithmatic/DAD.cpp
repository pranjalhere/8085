#include<iostream>
#include<string>
#include<map>
#include"../header/regisfun.h"
#include"../header/datafun.h"
#include"../header/Converter.h"

using namespace std;

void DAD(string data,string registers[],bool flag[]){

	int length = data.length();
	if(length == 1){
	    char arg = data[0];
		if(validReg(arg)){
		
			int registerID = registerNum(arg);
			if(registerID == 1 || registerID == 3 || registerID == 5){
				
				string data16bit = "";
				string data16bitHL = "";
				string resultant = "";
				if((validData(registers[registerID])) && (validData(registers[registerID+1])) && (validData(registers[5])) && (validData(registers[6]))){
				
					data16bit = data16bit + registers[registerID] + registers[registerID+1];
					data16bitHL = data16bitHL + registers[5] + registers[6];
					int value16bit[4];
					int value16bitHL[4];
					int carry = 0;
					Converter_h_to_D(data16bit,value16bit);
					Converter_h_to_D(data16bitHL,value16bitHL);	  
					for(int i = 3;i>=0;i--){
					
						int value = value16bit[i] + value16bitHL[i] + carry;
					
						if(value >= 16)
							flag[0] = true;
						else
							flag[0] = false;
						carry = value / 16;
						value = value % 16;
						if(value>=0 && value<=9){
							resultant = ((char)('0' + value) )+ resultant;
						}
						else{
							switch(value){
							
								case 10:
									resultant = 'A' + resultant;
									break;
								case 11:
									resultant = 'B' + resultant;
									break;
								case 12:
									resultant = 'C' + resultant;
									break;
								case 13:
									resultant = 'D' + resultant;
									break;
								case 14:
									resultant = 'E' + resultant;
									break;
								case 15:
									resultant = 'F' + resultant;
									break;	
							}
						}
					}
					string s1="";
					string s2="";
					for(int i=0;i<2;i++){
						s1+=resultant[i];
					}
					for(int i=2;i<4;i++){
						s2+=resultant[i];
					}
					registers[5]=s1;
					registers[6]=s2;

				}		
				else{
					
					cout<<"Error: Generated from the DAD command register pair contains invalid data"<<endl;
					exit(0);
					
				}
			}
			else{
				cout<<"Error: Generated from DAD Command Invalid Register"<<endl;
				exit(0);
				
			}
		}
		else{
			cout<<"Error: Generated from the DAD CommandYou are Trying Add with Invalid Register pair"<<endl;
		    exit(0);
			
		}
	}
	else{
		cout<<"Error: Generated from the DAD CommandYou are Trying Add with Invalid Register pair"<<endl;
		exit(0);
	}

}