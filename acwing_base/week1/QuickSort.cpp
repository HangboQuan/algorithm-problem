//
// Created by quanhangbo on 2021/11/2.
//

#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int arr[N];
//void swap(int arr[], int left, int right){
//    int temp = arr[left];
//    arr[left] = arr[right];
//    arr[right] = temp;
//}

//int position(int arr[], int left, int right){
//    int place = arr[left];
//    while(left < right){
//        while(left < right && arr[left] < place){
//            left ++;
//        }
//        while(left < right && arr[right] > place){
//            right --;
//        }
//        swap(arr, left, right);
//    }
//
//    for(int i = 0; i < right - left + 1; i ++ ){
//        cout << arr[i] << " ";
//    }
//    return left;
//}

//void quicksort(int arr[], int left, int right){
//    if(left == right){
//        return ;
//    }
//    int mid = position(arr, left, right);
//    quicksort(arr, left, mid);
//    quicksort(arr, mid + 1, right);
//}

// 排序仍有问题 待解决
void quick_sort(int arr[], int l, int r){
    if(l >= r) return;
    int x = arr[l], i = l - 1, j = r + 1;
    while(i < j){
        do i ++ ; while(arr[i] < x);
        do j -- ; while(arr[j] > x);
        if(i < j) swap(arr[i], arr[j]);
    }
    quick_sort(arr, l, j);
    quick_sort(arr, j + 1, r);
}
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ){
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i ++ ){
        printf("%d ", arr[i]);
    }
}


