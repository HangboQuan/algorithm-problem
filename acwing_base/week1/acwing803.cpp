//
// Created by quanhangbo on 2022/1/23 21:20.
//
// https://www.acwing.com/problem/content/805/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 1e5 + 10;

typedef pair<int, int> PII;
vector<PII> segs;


void merge(vector<PII> &segs){
    // 存储合并后的区间
    vector<PII> res;
    sort(segs.begin(), segs.end());

    // 数据范围是-1e9,1e9
    // 所以可以选择-2e9来作为边界条件(负无穷)
    int st = -2e9, ed = -2e9;
    for(auto item : segs){
        if(ed < item.first) {
            if(st != -2e9) res.push_back({st, ed});
            st = item.first, ed = item.second;
        }
        else{
            ed = max(ed, item.second);
        }

    }
    // 将最后一个区间添加进来
    if(st != -2e9) res.push_back({st, ed});

    segs = res;
}


int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge(segs);
    cout << segs.size() << endl;
}