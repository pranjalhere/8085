#include<iostream>
#include<string>
using namespace std;

string Complement(string s){
    int len = s.length();
    string comp="";
    
    for(int i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            int diff = 15-(s[i]-'0');
            if(diff>=0 && diff<=9){
                comp+=('0'+diff);
            }else if(diff>=10 && diff<=15){
                comp+=('A'+(diff-10));
            }
        }

        if(s[i]>='A' && s[i]<='F'){
            int value = s[i]-'A';
            int diff=15-value;
            if(diff>=0 && diff<=9){
                comp+=('0'+diff);
            }else if(diff>=10 && diff<=15){
                comp+=('A'+(diff-10));
            }
        }
    }
    return comp;
}