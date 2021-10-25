//
// Created by quanhangbo on 2021/9/20.
//
#include<iostream>
#include<vector>

using namespace std;


int getNumberOfK(vector<int>& nums , int k) {
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == k) {
            cnt++;
        }
    }
    return cnt;
}

int getNumberOfK2(vector<int>& nums , int k) {
    // 使用二分
    if(nums.empty()){
        return 0;
    }
    int l = 0, r = nums.size() - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(nums[mid] != mid){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if(r == nums[r]){
        r++;
    }
    return r;

}

void hello(){
    vector<int> ans = {0, 3, 2, 5, 8, 4, 7, 6};
    int n = ans.size();
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 2; j--){
            if(ans[j] < ans[j - 1]) {
                int t = ans[j - 1];
                ans[j - 1] = ans[j];
                ans[j] = t;
            }
        }
    }
    for(auto x : ans){
        cout << x << " ";
    }
}

void test(){
    int a, n;
    while(cin >> n && n > 1){
        cout << n;
    }
}


int main(){


//    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    for(int i = 0; i < v.size(); i++){
//        cout << v[i] << endl;
//    }
//
//    vector<int> ans(5, 1);
//    for(int i = 0; i < ans.size(); i++){
//        cout << ans[i] << endl;
//    }
//
//    string a = "123";
//    cout << a.length() << a.size();
//    a.replace(0, 1, "1");
//    cout << a;
//
//    test();
//    cout << endl;
//    vector<int> arr{1, 2, 3, 3, 3, 3, 4, 5};
//    cout << getNumberOfK(arr, 3);

    //test();
    hello();
    return 0;

}
