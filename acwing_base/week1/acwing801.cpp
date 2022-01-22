//
// Created by quanhangbo on 2022/1/22 12:04.
//

#include<iostream>
using namespace std;

/*求出最右面的1的位置*/
int lowbit(int x){
    return x & -x;
}
int main(void){

    int n;
    cin >> n;

    while(n -- ){
        int x;
        cin >> x;

        int res = 0;
        while(x){

            x -= lowbit(x);
            res ++;
        }
        cout << res << " ";
    }
    return 0;
}