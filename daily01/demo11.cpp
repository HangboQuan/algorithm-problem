//
// Created by quanhangbo on 2021/10/30.
//

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1005;
int main(void){
    int T;
    cin >> T;
    int a[N];
    for(int i = 1; i <= T; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + T);
    for(int i = T; i >= 1; i --){

        double res = sqrt((double)abs(a[i]));
        int b = sqrt((double)abs(a[i]));
        cout << res << " " << b << endl;
        if(res - b != 0){
            cout << a[i];
            break;
            //return ;
        }
    }
    return 0;
}

