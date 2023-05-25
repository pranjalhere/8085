#include<iostream>
#include<string>
using namespace std;
string increaseAddress(string a){
    int num[5];

    string nxtadd="";
    int l = a.length();
    for(int i=l-1;i>=0;i--){
        if(a[i]>='A' && a[i]<='F'){
                num[i]=(int)(10+a[i]-'A');
        }

        if(a[i]>='0' && a[i]<='9'){
            num[i] = (int)(a[i]-'0');
        }
    }

    num[l-1]++;

    for(int i=l-1;i>=0;i--){
        if(num[i]>=0 && num[i]<=15){
            break;
        }
        if(num[i]>=16){
            num[i]=num[i]%16;
            num[i-1]++;
        }
    }

    for(int i=0;i<l;i++){
        if(num[i]>=0 && num[i]<=9){
            nxtadd+=(char)('0'+num[i]);
        }else if(num[i]>=10 && num[i]<=15){
            nxtadd+=(char)('A'+(num[i]-10));
        }
    }

    return nxtadd;
}