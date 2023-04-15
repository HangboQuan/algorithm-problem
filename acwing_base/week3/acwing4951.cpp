//
// Created by quanhangbo on 2023/4/15.
//

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;


char op;
int p, q, n, s;

bool great(PII a, PII b) {
    return a.first > b.first;
}

int main(void) {
    scanf("%d%d", &n, &s);
    unordered_map<LL, LL> bm;
    unordered_map<LL, LL> sm;

    vector<PII> bv;
    vector<PII> sv;
    for (int i = 0; i < n; i ++ ) {
        cin >> op >> p >> q;
        if (op == 'B') {
            if (bm.count(p)) {
                bm[p] = bm[p] + q;
            } else {
                bm[p] = q;
            }
//            bv.push_back(make_pair(p, bm[p]));

        } else {
            if (sm.count(p)) {
                sm[p] = sm[p] + q;
            } else {
                sm[p] = q;
            }
//            sv.push_back(make_pair(p, sm[p]));
        }
    }

    for (auto& it : sm) {
        sv.push_back(make_pair(it.first, it.second));
    }
    for (auto& it : bm) {
        bv.push_back(make_pair(it.first, it.second));
    }

    sort(bv.begin(), bv.end(), great);
    sort(sv.begin(), sv.end(), great);



    if (s < sv.size()) {
        for (int i = s; i > 0; i -- ) {
            cout << "S " << sv[sv.size() - i].first << " " << sv[sv.size() - i].second << endl;
        }
    } else {
        for (int i = 0; i < sv.size() && i < s; i ++ ) {
            cout << "S " << sv[i].first << " " << sv[i].second << endl;
        }
    }
    for (int i = 0; i < bv.size() && i < s; i ++ ) {
        cout << "B " << bv[i].first << " " << bv[i].second << endl;
    }
    return 0;

}