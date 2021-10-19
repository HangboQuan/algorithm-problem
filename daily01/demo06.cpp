//
// Created by quanhangbo on 2021/10/2.
//
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

int n, k;
unordered_map<int, int> map;

int main(void){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        map[x] = i;
    }

    if(map.size() < k) puts("NO");
    else{
        puts("YES");
        int cnt = 0;
        for(auto [x, v] : map){
            if(++cnt > k) break;
            cout << v << ' ';
        }
    }
}
