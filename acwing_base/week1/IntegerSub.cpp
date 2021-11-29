//
// Created by quanhangbo on 2021/11/29 20:04.
//
#include<iostream>
#include<vector>
using namespace std;
// 大整数相减 两个整数都是负数
bool cmp(vector<int> &A, vector<int> &B){
    if(A.size() != B.size()) return A.size() >= B.size();
    for(int i = A.size() - 1; i >= 0; i -- ){
        if(A[i] != B[i]){
            return A[i] > B[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;
    for(int i = 0, t = 0; i < A.size(); i ++ ){
        t = A[i] - t;
        if(i < B.size()) t -= B[i];

        // (t + 10) % 10在这里综合了两种情况：t > 0 ? t : t + 10
        C.push_back((t + 10) % 10);
        // t < 0 则说明需要借位
        if(t < 0) t = 1;
        else t = 0;
    }
    // 去除前导0
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
int main(void){
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    // 判断a和b谁大 A >= B
    if(cmp(A, B)){
        auto C = sub(A, B);
        for(int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    }else{
        auto C = sub(B, A);
        printf("-");
        for(int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);

    }
    return 0;

}
