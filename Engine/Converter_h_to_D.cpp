#include<iostream>
#include<vector>
#include<string>

using namespace std;

void Converter_h_to_D(string pc_r,int arr[]){
    int len=pc_r.length();
    int p=0;
    for(int i=0;i<len;i++){
        if(pc_r[i]>='0' && pc_r[i]<='9'){
            arr[i]=pc_r[i]-'0';
        }else{
            arr[i]=10+(pc_r[i]-'A');
        }
    }
}