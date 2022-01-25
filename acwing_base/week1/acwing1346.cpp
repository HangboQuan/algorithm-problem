//
// Created by quanhangbo on 2022/1/25 12:36.
//
// https://www.acwing.com/problem/content/description/1348/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string convertToBReflection(int res, int b){
    string s = "";
    while(res != 0){
        int a = res % b;
        if(a >= 10){
            s += ('A' - 10 + a);
        }else{
            s += to_string(a);
        }

        res = res / b;
    }

    reverse(s.begin(), s.end());
    return s;
}

bool isPalindrome(string a){
    int i = 0, j = a.size() - 1;
    while(i < j){
        if(a[i] == a[j]){
            i ++;
            j --;
        }else{
            return false;
        }
    }
    return true;
}
int main(void){
    int b;
    cin >> b;
    for(int i = 1; i <= 300; i ++ ){
        int res = i * i;
        // 将res转化为b进制
        string o = convertToBReflection(i, b);
        string s = convertToBReflection(res, b);


        // 判断结果是否为回文
        if(isPalindrome(s)){
            cout << o << " " << s << endl;
        }
    }

    return 0;
}