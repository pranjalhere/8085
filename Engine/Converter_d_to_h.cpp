#include<iostream>
#include<string>

using namespace std;

string Converter_d_to_h(int decimal[]){
    string hex="";

    int size=sizeof(decimal)/sizeof(decimal[0]);
    for(int i=0;i<size();i++){
        if(decimal[i]>=0 && decimal[i]<=9){
            hex+=(char)('0'+decimal[i]);
        }else if(decimal[i]>=10 && decimal[i]<=15){
            hex+=(char)('A'+(decimal[i]-10));
        }
    }
    return hex;
}