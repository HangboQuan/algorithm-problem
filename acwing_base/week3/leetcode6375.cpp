//
// Created by quanhangbo on 2023/4/16 21:21.
//

#include<iostream>
#include<map>
using namespace std;

int addMinimum(string word) {
    map<char, int> m;
    for (int i = 0; i < word.size(); i ++ ) {
        m[word[i]] ++;
    }

//    cout << m['a'] << m['b'] << m['c'] << endl;

    if (m['a'] == m['b'] && m['b']== m['c'] && m['a'] == m['c']) {
        return 0;
    } else {
        int x = max(m['a'], max(m['b'], m['c']));
        if (x % 3 != 0) {
            int target = x;
            while (target % 3 == 0) {
                target ++;
            }
        }
        int num = 0;
        num += 3 * x - (m['a'] + m['b'] + m['c']);
        return num;
    }

}

int main(void) {
    cout << addMinimum("abc");
}
