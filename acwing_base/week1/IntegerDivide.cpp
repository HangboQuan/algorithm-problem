//
// Created by quanhangbo on 2021/11/30 22:49.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r){
    vector<int> C;
    r = 0;
    for(int i = A.size() - 1; i >= 0; i -- ){
        C.push_back((r * 10 + A[i]) / b);
        r = (r * 10 + A[i]) % b;
    }
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main(void){
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    int r;
    auto C = div(A, b, r);

    for(int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
    cout << endl << r << endl;
    return 0;
}