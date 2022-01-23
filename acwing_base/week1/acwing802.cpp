//
// Created by quanhangbo on 2022/1/22 15:41.
//

/**
 * https://www.acwing.com/problem/content/804/
 * 离散化
 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// 开30w长度的数组的原因是 数据范围n为10w,然后[l, r]是2m个,为20w个
const int N = 3e5 + 10;

typedef pair<int, int> PII;
// 存储离散化后的下标数据
vector<int> alls;
vector<PII> add, query;

int a[N], s[N];
int find(int x){
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    // 这里为了前缀和方便使用，返回的下表是从1开始的
    return l + 1;
}
int main(void){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        alls.push_back(x);
    }

    for(int i = 0; i < m; i ++ ){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 构造原始数据
    for(auto item : add){
        int x = find(item.first);
        a[x] += item.second;
    }

    for(int i = 1; i <= alls.size(); i ++ ){
        s[i] = s[i - 1] + a[i];
    }

    for(auto item : query){
        int l = find(item.first);
        int r = find(item.second);

        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}