//
// Created by quanhangbo on 2021/11/30 19:47.
//

#include<iostream>
#include<vector>

// 大整数相乘
// 数据范围是 a的位数 <= 10^5,b < 10^5
using namespace std;

/*vector<int> mult(vector<int> &A, int b){
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i ++ ){
        // t是进位
        C.push_back((A[i] * b + t) % 10);
        t = (A[i] * b + t) / 10;
    }
    // 后面的进位
    if(t) C.push_back(t);
    // 去除前导0，比如123*0==>000==>0
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}*/

vector<int> mult(vector<int> &A, int b){
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size() || t; i ++ ){
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
int main(void){
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');


    auto C = mult(A, b);
    for(int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    return 0;
}