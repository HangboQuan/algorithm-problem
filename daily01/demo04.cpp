//
// Created by quanhangbo on 2021/9/20.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int sumOfBeauties(vector<int>& nums){
    int n = nums.size();
    vector<int> left_max(n, INT_MIN);
    left_max[0] = nums[0];
    vector<int> right_min(n, INT_MAX);
    right_min[n - 1] = nums[n - 1];
    // i位置保存了i位置左边最大的数，以及i位置右边最小的数
    for(int i = 1; i < n; i++){
        left_max[i] = max(left_max[i - 1], nums[i - 1]);
    }

    for(int i = n - 2; i > 0; i--){
        right_min[i] = min(right_min[i + 1], nums[i + 1]);
    }

    int ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(nums[i] > left_max[i] && nums[i] < right_min[i]){
            ans += 2;
        }else if(nums[i] > nums[i - 1] && nums[i] < nums[i + 1]){
            ans += 1;
        }
    }

    return ans;
}

int main(){
    // 统计大于40的数
    // stl中的 容器 算法 迭代器 分配器 仿函数 仿函数适配器
    int  ia[6] = {27, 210, 12, 47, 109, 83};
    vector<int, allocator<int>> vi (ia, ia + 6);
    // begin 和 end 遵循 前闭后开   容器(不一定是连续的空间) 迭代器是一种泛化的指针
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));
    // less 为仿函数 bind2nd为仿函数适配器

    cout << endl;
    vector<int> a {1, 2, 3, 4};
    vector<int> :: iterator v;
    for(v = a.end() - 1; v >= a.begin(); v--){
        cout << *v << " ";
    }

    vector<int> vv {1, 2, 3};
    cout << sumOfBeauties(vv);



}


