//
// Created by quanhangbo on 2023/3/9 19:02.
//

#include<iostream>
#include<vector>
using namespace std;

void dfs(int i, vector<int>& v, bool st[], vector<int>& vec) {
    if (i == vec.size()) {
        for(int j = 0; j < v.size(); j ++ ) {
            cout << v[j] << " ";
        }
        cout << endl;
        return ;
    }

    for(int x = 0; x < vec.size(); x ++) {
        if (!st[x]) {
            v.push_back(vec[x]);
            st[x] = true;
            dfs(i + 1, v, st, vec);
            st[x] = false;
            v.pop_back();
        }
    }

}
int main(void) {
    vector<int> vec = {1, 2, 3, 4};
    vector<int> v;
    bool st[vec.size()];
    dfs(0, v, st, vec);
}