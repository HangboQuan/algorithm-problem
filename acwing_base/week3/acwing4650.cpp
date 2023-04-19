//
// Created by quanhangbo on 2023/4/19.
//
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long LL;

vector<LL> prime;
int t;

// isPrime
bool isPrime() {
    prime.push_back(2);
    for (LL i = 3; i < 10e5; i ++ ) {
        LL j = 2;
        for (; j <= sqrt(i); j ++ ) {
            if (i % j == 0) {
                break;
            }
        }
        if (j > sqrt(i)) {
            prime.push_back(i);
        }
    }
    cout << prime.size() << endl;
}

int main(void) {
    isPrime();
}
