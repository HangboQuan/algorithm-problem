//
// Created by quanhangbo on 2021/9/20.
//
#include<iostream>
#include<vector>
using namespace std;

int finalValueAfterOperation(vector<string>& operations){
    int res = 0;
    for(auto a : operations){
        if(a[1] == '+') res++; else res--;
    }
    return res;
}

int main(){
    vector<string> str {"++x", "--x", "x++"};
    cout << finalValueAfterOperation(str) << endl;
}
