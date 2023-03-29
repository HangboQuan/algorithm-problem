//
// Created by quanhangbo on 2023/3/29 20:21.
//

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> findNumbersWithSum(vector<int>& nums, int target) {
    unordered_set<int> S;
    for (auto x : nums) {
        if (S.count(target - x)) {
            return {x, target - x};
        }
        S.insert(x);
    }
}
int main(void) {

}