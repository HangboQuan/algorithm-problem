//
// Created by quanhangbo on 2021/11/2.
//

/*
 * 使用STL vector
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<int, pair<double, string>> PII;

vector<PII> ans;

int n, a;
double b;
string c;
int main(){
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        cin >> a >> b >> c;
        ans.push_back({a, {b, c}});
    }
    sort(ans.begin(), ans.end());
    for(auto i : ans){
        printf("%d %.2lf %s\n", i.first, i.second.first, i.second.second.c_str());
    }
}
*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>

const int N = 100010;
using namespace std;
typedef pair<double, string> PII;

// map 默认是有序的
map<int, PII> ans;

int main(void){
    int n, a;
    double b;
    string c;
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        cin >> a >> b >> c;
        ans.insert({a, {b, c}});
    }

    for(auto i : ans){
        printf("%d %.2lf %s\n", i.first, i.second.first, i.second.second.c_str());
    }
}



