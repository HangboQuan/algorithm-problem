//
// Created by quanhangbo on 2021/11/7 14:42.
//
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int arr[N];
int binary_search(int arr[], int l, int r, int target){

    while(l < r){
        int mid = l + r >> 1;
        if(arr[mid] >= target) r = mid;
        else l = mid + 1;
    }
    if(arr[l] != target){
        return -1;
    }
    return l;
}

int binary_search2(int arr[], int l, int r, int target){
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(arr[mid] <= target) {
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    if(arr[l] != target){
        return -1;
    }
    return l;
}
int main(void){


    // 给定一个有序数组，返回一个数最左边出现的下标和最右边出现的下标
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ){
        scanf("%d", &arr[i]);
    }

    int target = 3;
    // 如果查询不到值 则返回
    // cout << binary_search(arr, 0, n - 1, target) << endl;
    cout << binary_search2(arr, 0, n - 1, target) << endl;
}
