//
// Created by quanhangbo on 2022/1/18 21:58.
//

#include<iostream>
using namespace std;


const int N = 1e5 + 10;
int a[N], s[N];
int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i ++ ){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    // 双指针算法，其中i表示的是结果区间的右端，j表示的是结果区间的左端
    // s数组表示的是 一个数出现的次数 每出现一个数的时候如果发现s[a[i]] > 1,即当前添加的元素a[i]就是重复元素，
    // 移除最左端的a[j]元素，j向后移动 => 每循环一次 更新一次max
    for(int i = 0, j = 0; i < n; i ++ ){
        s[a[i]] ++;
        while(j < i && s[a[i]] > 1){
            s[a[j]] --;
            j ++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl;
    return 0;

}