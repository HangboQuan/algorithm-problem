//
// Created by quanhangbo on 2022/1/24 12:31.
//
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<int, int> PII;
vector<PII> segs;

void merge(vector<PII> &segs){

    sort(segs.begin(), segs.end());
    // 用一个新的数组来存储合并后的区间
    vector<PII> res;
    int st = -2e5, ed = -2e5;
    for(auto item : segs){
        if(ed < item.first){
            if(st != -2e5) res.push_back({st, ed});
            st = item.first, ed = item.second;
        }else{
            ed = max(ed, item.second);
        }
    }

    if(st != -2e5) res.push_back({st, ed});
    segs = res;
}

int longestSubstringWithoutDuplication(string s) {
    int n = s.size();
    int a[n];
    int v = 0;
    for(int i = 0, j = 0; i < n; i ++ ){
        a[s[i]] ++;
        while(a[s[i]] > 1){
            a[s[j]] --;
            j ++;
        }
        v = max(v, i - j + 1);
    }
    return v;
}

int main(void){

    string a;
    cin >> a;
    cout << longestSubstringWithoutDuplication(a);
    /*int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++ ){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }


    merge(segs);
    int total = n + 1;
    for(auto item : segs){
        int num = item.second - item.first + 1;
        total -= num;
    }
    cout << total << endl;
    return 0;*/
}


