//
// Created by quanhangbo on 2023/4/9 18:45.
//

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int N = 1000010;

int m;
int countTwo = 0;
int countFive = 0;
int countTen = 0;

int main() {
    scanf("%d", &m);
    unordered_map<int, int> mt;
    for (int i = 1; i <= N; i ++ ) {
        int rt = i;
        while (rt % 10 == 0 && rt != 0) {
            countTen ++;
            rt /= 10;
        }
        while (rt % 5 == 0 && rt != 0) {
            countFive ++;
            rt /= 5;
        }
        while (rt % 2 == 0 && rt != 0) {
            countTwo ++;
            rt /= 2;
        }

        mt[i] = min(countTwo, countFive) + countTen;
    }

    int i = 1;
    bool tag = false;
    vector<int> vec;
    int count = 0;
    for (; i <= N; i ++ ) {
        if (mt[i] == m) {
            count ++;
            vec.push_back(i);
            tag = true;
        }

        if (mt[i] > m && !tag) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << count << endl;
    for (auto& x : vec) {
        cout << x << " ";
    }
    return 0;
}