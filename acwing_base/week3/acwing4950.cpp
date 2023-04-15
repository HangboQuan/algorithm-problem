//
// Created by quanhangbo on 2023/4/15.
//

#include<iostream>
using namespace std;

double a, b, c;
int main(void) {
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("%.4f", (a * b) / (b + c));
    return 0;
}