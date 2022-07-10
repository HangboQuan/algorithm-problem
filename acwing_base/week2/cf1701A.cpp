//
// Created by quanhangbo on 2022/7/10 16:49.
//

// // https://codeforces.com/contest/1701/problem/A
#include<iostream>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t -- ){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = a + b + c + d;
        if(sum == 0){
            cout << 0 << endl;
        }else if(sum == 4){
            cout << 2 << endl;
        }else{
            cout << 1 << endl;
        }
    }
    return 0;
}