//
// Created by quanhangbo on 2023/3/9 19:02.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//void dfs(int i, vector<int>& v, bool st[], vector<int>& vec) {
//    if (i == vec.size()) {
//        for(int j = 0; j < v.size(); j ++ ) {
//            cout << v[j] << " ";
//        }
//        cout << endl;
//        return ;
//    }
//
//    for(int x = 0; x < vec.size(); x ++) {
//        if (!st[x]) {
//            v.push_back(vec[x]);
//            st[x] = true;
//            dfs(i + 1, v, st, vec);
//            st[x] = false;
//            v.pop_back();
//        }
//    }
//
//}
//int main(void) {
//    vector<int> vec = {1, 2, 3, 4};
//    vector<int> v;
//    bool st[vec.size()];
//    dfs(0, v, st, vec);
//}

vector<vector<int>> vec;
void dfs(int step, vector<int>& v, bool st[], vector<int>& nums) {
    if (step == nums.size()) {
        for(int i = 0; i < v.size(); i ++ ) {
            cout << v[i] << " ";
        }
        if (count(vec.begin(), vec.end(), v)) {
            ;
        } else {
            vec.push_back(v);
        }
        cout << endl;
        return ;
    }

    for (int i = 0; i < nums.size(); i ++ ) {
        if (!st[i]) {
            v.push_back(nums[i]);
            st[i] = true;
            dfs(step + 1, v, st, nums);
            st[i] = false;
            v.pop_back();
        }
    }


}
vector<vector<int>> permutation(vector<int>& nums) {
    vector<int> v;
    bool st[nums.size()];
    // 第一位步数 第二位结果数组 第三位记录状态 第四位原数组
    dfs(0, v, st, nums);
    return vec;
}

int main(void) {
    vector<int> vec = {1, 2, 3};
    vector<vector<int>> v = permutation(vec);
    for(vector<int>& u: v) {
        for(auto& x : u) {
            cout << x << " ";
        }
        cout << endl;
    }
}
