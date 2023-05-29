#include<iostream>
#include <sstream>
using namespace std;
int Arraytoint(int arr[]) {
    stringstream ss;


    for (unsigned i = 0; i<4; ++i)
        ss << arr [i];

    int result;
    ss >> result;
    return result;
}