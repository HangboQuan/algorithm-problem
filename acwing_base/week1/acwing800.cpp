//
// Created by quanhangbo on 2022/1/19 9:59.
//

#include<iostream>
#include<set>
using namespace std;

/**
 *
4 5 6
1 2 4 7
3 4 6 8 9
 */
const int N = 1e5 + 10;
int a[N], b[N];
int main(void){
    int n, m, target;
    set<int> s;
    cin >> n >> m >> target;
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    for(int j = 0; j < m; j ++ ){
        cin >> b[j];
        s.insert(b[j]);
    }

    // 利用升序的特点 binarySearch

    for(int i = 0; i < n; i ++ ){
        int result = target - a[i];
        if(s.count(result)){
            int l = 0, r = m - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(b[mid] >= result){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            cout << i << " " << l << endl;
        }
    }
    return 0;
}