//
// Created by quanhangbo on 2022/1/30 20:58.
//
// 双向链表
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int e[N], l[N], r[N], idx;

void init(){
    l[1] = 0;
    r[0] = 1;
    idx = 2;
}


void add_to_k(int k, int x){
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}

void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}


int main(void){
    int m;
    cin >> m;
    init();
    while(m -- ){
        string op;
        cin >> op;
        int k, x;
        if(op == "R"){
            cin >> x;
            add_to_k(l[1], x);
        }else if(op == "L"){
            cin >> x;
            add_to_k(0, x);
        }else if(op == "D"){
            cin >> k;
            remove(k + 1);
        }else if(op == "IL"){
            cin >> k >> x;
            add_to_k(l[k + 1], x);
        }else if(op == "IR"){
            cin >> k >> x;
            add_to_k(k + 1, x);
        }
    }

    for(int i = r[0]; i != 1; i = r[i]){
        cout << e[i] << " ";
    }
    cout << endl;
    return 0;
}