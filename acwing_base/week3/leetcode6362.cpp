//
// Created by quanhangbo on 2023/4/2 15:03.
//

#include<string>
#include<iostream>
using namespace std;


class Solution {

public:

    int max = 0;
    bool isBlanceString(string s) {
        if (s.size() % 2 != 0) return false;
        for (int i = 0; i < s.size() / 2; i ++ ) {
            if (s.at(i) != '0') {
                return false;
            }
        }

        for (int i = s.size() / 2; i < s.size(); i ++ ) {
            if (s.at(i) != '1') {
                return false;
            }
        }
        return true;
    }

    int findTheLongestBalancedSubstring(string s) {

        if (s.size() == 0) {
            return 0;
        }

        for (int i = 0; i < s.length(); i ++ ) {
            for (int j = 2; j <= s.length(); j ++ ) {
                if (isBlanceString(s.substr(i, j))) {
                    int len = s.substr(i, j).size();
                    if (len > max) {
                        max = len;
                    }
                }
            }
        }
        return max;
    }
};
int main(void) {
    Solution* sol = new Solution();
    cout << sol->findTheLongestBalancedSubstring("00010");
}