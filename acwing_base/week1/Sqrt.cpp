//
// Created by quanhangbo on 2021/11/7 20:23.
//
#include<iostream>
using namespace std;
double mySqrt(int x) {
    double l = 0;
    double r = x;
    while(r - l > 1e-8){
        double mid = (l + r) / 2;
        if(mid * mid >= x) r = mid;
        else l = mid;
    }
    cout << "l = " << l << endl;
    return l;
}

int mySqrt2(int x){
    int l = 0, r = x, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main(void){
    double a = mySqrt(4);
    printf("%llf\n", a);
    printf("%llf\n", mySqrt(4));
    printf("%d\n", mySqrt2(4));
}
