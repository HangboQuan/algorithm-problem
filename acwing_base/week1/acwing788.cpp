//
// Created by quanhangbo on 2021/11/7 19:13.
//
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int arr[N], tmp[N];

long long result = 0;

// 题目链接：https://www.acwing.com/problem/content/description/790/
void merge_sort(int arr[], int l, int r){
    if(l >= r) return ;
    // 找到中点
    int mid = l + r >> 1;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    // 合并
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        // for(int i = l; i <= r; i ++ ){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        if(arr[i] <= arr[j]) {
            tmp[k ++] = arr[i ++];

        }
        else {
            tmp[k ++] = arr[j ++];
            // 逆序对：分为3种情况讨论
            /*
                1.出现在[l, mid]
                2.出现在[mid + 1, r]
                3.出现在[l, r], 经过mid中点
            */

            /*
                在这里的时候，此时两个子数组都是有序的，正在将它们进行合并
                对于左边数组arr[l, mid]中存在i, 右边数组arr[mid + 1, r]中存在j
                此时i 必然大于 j, 如果arr[i] > arr[j]的话，由于有序，则左边数组中arr[i, mid] 中的元素也比大于
                arr[j],此处的mid - i + 1,就是左边数组中大于arr[j]的个数
            */
            result += mid - i + 1;
        }
    }
    while(i <= mid){
        tmp[k ++] = arr[i ++];
    }
    while(j <= r){
        tmp[k ++] = arr[j ++];
    }

    // 如果是归并排序的话，再将tmp数组复制会元素组
    for(int i = l, j = 0; i <= r; i ++, j ++ ){
        arr[i] = tmp[j];
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ){
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("%lld", result);


}
