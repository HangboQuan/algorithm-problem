////
//// Created by quanhangbo on 2022/1/20 20:59.
////
//
////https://www.acwing.com/problem/content/description/3496/
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1e5 + 10;
//
//int a[N], b[N];
//long s[N];
///**
// * 此类问题主要是转化：该问题可以转为s固定 + s区间最大值
// * s区间最大值 => s区间不可选的值最大
// * @return
// */
//int main(void){
//    int n, k;
//    cin >> n >> k;
//    for(int i = 0; i < n; i ++ ){
//        cin >> a[i];
//    }
//    for(int i = 0; i < n; i ++ ){
//        cin >> b[i];
//        s[i + 1] = (b[i] == 0 ? a[i] : 0) + s[i];
//    }
//    long res = 0;
//    for(int i = 0; i < n; i ++ ){
//        res += b[i] == 0 ? 0 : a[i];
//    }
//
//    long v = 0;
//    for(int i = k; i < n + 1; i ++ ){
//        v = max(v, s[i] - s[i - k]);
//    }
//
//    cout << res + v << endl;
//    return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int a[N], b[N];
int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    for(int i = 0; i < n; i ++ ) scanf("%d", &b[i]);
    LL res = 0;
    // 原始固定的res
    for(int i = 0; i < n; i ++ ){
        res += b[i] == 0 ? 0 : a[i];
    }

    LL v = 0, s = 0;
    for(int i = 0; i < n; i ++ ){
        s += a[i];
        if(i >= k && !b[i - k]) s -= a[i - k];
        v = max(v, s);
    }
    cout << res + v << endl;
    return 0;
}