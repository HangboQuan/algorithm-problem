//
// Created by quanhangbo on 2021/11/13 17:47.
//
#include<iostream>
using namespace std;

// 求三次开根号 二分
double check(double mid){
    return mid * mid * mid;
}
int main(void){
    double n;
    cin >> n;
    // 这里不能写为l = 0, r = a对于整数能过测试,但是对于负数则会出现问题，因此需将l,r的取值范围定的大一些
    double l = -10000, r = 10000;
    while(r - l > 1e-8){
        double mid = (l + r) / 2;
        if(check(mid) >= n){
            r = mid;
        }else{
            l = mid;
        }
    }
    printf("%.6llf", l);
}