//
// Created by quanhangbo on 2022/2/14 12:44.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100010;
// leetcode280周赛 前三题代码
// 1.
int countOperations(int num1, int num2) {
    int res = 0;
    while(num1 != 0 || num2 != 0){
        if(num1 >= num2){
            num1 -= num2;
        }else{
            num2 -= num1;
        }
        res ++;
    }
    return res;
}

// 2.思路：将数组按照下标分为奇数数组和偶数数组，求出奇数数组中记最多出现的元素为x,偶数数组中记最多出现的元素为y
// if x != y 则保留x, y,即为最小的操作数
// if x == y 则记奇数数组中次多出现的元素为x',偶数数组中次多出现的元素为y' 保留x 和 y' 或者 x' 和 y 这两种情况的最大值
// 没有次大值的时候 可以用0来代替

vector<int> gos(vector<int>& count){
    vector<int> res;
    // 求出maxValue, maxCount, nmaxValue, nmaxCount
    int maxValue = -1, nmaxValue = 0;
    int maxCount = -1, nmaxCount = 0;
    for(int i = 0; i < count.size(); i ++ ){
        if(count[i] > maxCount){
            nmaxCount = maxCount;
            maxCount = count[i];
            nmaxValue = maxValue;
            maxValue = i;
        }else if(count[i] > nmaxCount){
            nmaxCount = count[i];
            nmaxValue = i;
        }
    }
    res = {maxValue, maxCount, nmaxValue, nmaxCount};
    return res;

}
int minimumOperations(vector<int>& nums) {
    vector<int> odd_count(N), even_count(N);
    for(int i = 0; i < nums.size(); i ++ ){
        if(i % 2 == 0){
            odd_count[nums[i]] ++;
        }else{
            even_count[nums[i]] ++;
        }
    }
    auto f0 = gos(odd_count);
    auto f1 = gos(even_count);
    int res = f0[1] + f1[1];
    if(f0[0] == f1[0]){
        // 出现次数最多的元素相等
        res = max(f0[1] + f1[3], f0[3] + f1[1]);
    }

    return nums.size() - res;
}

// 拿出最小的豌豆 ==> 剩余最多的豌豆数
// 先进行排序 枚举每一个豌豆v，左边的豌豆都比他少清空，右边的的元素x都比他多x - i
// 当豌豆为v时 留下的豌豆数最大
long long minimumRemoval(vector<int>& beans) {
    sort(beans.begin(), beans.end());
    long long sum = 0;
    for(int i = 0; i < beans.size(); i ++ ){
        sum += beans[i];
    }
    long long res = 0;
    for(int i = 0; i < beans.size(); i ++ ){
        long long temp = beans[i] * (beans.size() - i);
        res = max(res, beans[i] * temp);
    }
    
    return sum - res;
}
int main(void){

}
