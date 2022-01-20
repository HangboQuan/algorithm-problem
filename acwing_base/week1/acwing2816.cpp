/*
//
// Created by quanhangbo on 2022/1/20 14:20.
//

#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }

    for(int i = 0; i < m; i ++ ){
        cin >> b[i];
    }
    int count = 0;
    for(int i = 0, j = 0; i < n; i ++ ){
        while(j < m && a[i] != b[j]) j ++;
        if(a[i] == b[j] && j < m) {
            count ++;
            if(a[n - 1] == b[j] && count == n){
                cout << "Yes" << endl;
                return 0;
            }
            j ++;
        }
    }
    cout << "No" << endl;
    return 0;

}

*/

#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }

    for(int i = 0; i < m; i ++ ){
        cin >> b[i];
    }

    int i = 0;
    for(int j = 0; j < m; j ++ ){
        if(i < n && a[i] == b[j]) i ++;
    }
    if(i == n) puts("Yes");
    else puts("No");

    return 0;
}