//
// Created by quanhangbo on 2021/11/21 21:45.
//

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class RangeFreqQuery {
    unordered_map<int, vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        // emplace_back 和push_back 类似，区别是前者不需要触发拷贝构造和转移构造
        for(int i = 0; i < arr.size(); i ++ ){
            // value存的是下标 必然有序 二分
            mp[arr[i]].emplace_back(i);
        }
    }

    int query(int left, int right, int value) {
        // count()作用是判断value是否存在于map中，如果不存在返回0，否则返回1
        if(!mp.count(value)){
            return 0;
        }
        // 注意得写为下面的写法 上面的写法不通过
        // vector<int> v = mp[value];
        auto &v = mp[value];
        for(int i = 0; i < v.size(); i ++ ){
            cout << v[i] << " ";
        }
        cout << endl;
        // upper_bound 从数组的begin~end-1 查找第一个大于num的数字
        auto r = upper_bound(v.begin(), v.end(), right);
        auto l = upper_bound(v.begin(), v.end(), left - 1);
        return r - l;
    }
};

int main(){
    vector<int> v = {12, 33, 4, 4, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery rangeFreqQuery = RangeFreqQuery(v);
    int result = rangeFreqQuery.query(1, 3, 4);
    cout << result << endl;
}