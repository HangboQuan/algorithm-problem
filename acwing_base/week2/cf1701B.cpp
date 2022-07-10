//
// Created by quanhangbo on 2022/7/10 20:45.
//

// https://codeforces.com/contest/1701/problem/B
#include<iostream>
#include<set>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while( t -- ){
        int n;
        cin >> n;
        // 只有是2的时候，才能得到最大长度
        cout << 2 << endl;
        set<int> s;
        for(int i = 1; i <= n; i ++ ){
            if(s.find(i) == s.end()){
                int cur = i;
                while(cur <= n){
                    cout << cur << " ";
                    s.insert(cur);
                    cur *= 2;
                }
            }

        }
        cout << endl;
    }
}