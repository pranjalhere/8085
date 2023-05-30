#include<iostream>
#include<string>
using namespace std;

string nextAddress(string pc,int operation){
    int arr[4]={0,0,0,operation};
    for(int i=3;i>=0;i--){
        if(pc[i]>='0' && pc[i]<='9'){
            int k = (pc[i]-'0')+arr[i];
            if(k>=0 && k<=9){
                pc[i]='0'+ k;
            }
            else{
                pc[i]=((k-10)+'A');
            }

        }
        else if(pc[i]>='A' && pc[i]<='F'){
            int k = pc[i]-'A'+10;
            k+=arr[i];
            k=k%10;
            pc[i]='A'+k;

            if(pc[i]>'F'){
                int k = pc[i]-'F';
                pc[i]='0'+k-1;
                if(i!=0){
                    pc[i-1]++;
                }
            }
        }
    }
    return pc;
}