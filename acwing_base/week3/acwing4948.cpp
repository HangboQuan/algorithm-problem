//
// Created by quanhangbo on 2023/4/9 17:22.
//

//#include<iostream>
//using namespace std;
//
//const int N = 100010;
//string arr[N];
//int n;
//
//int main() {
//
//    scanf("%d", &n);
//    string result;
//    int countZero = 0;
//    for (int i = 0; i < n; i ++ ) {
//        cin >> arr[i];
//        if (arr[i] == "0") {
//            cout << 0 << endl;
//            return 0;
//        }
//        // 判断是否为美丽数
//        if (arr[i][0] == '1') {
//            int left = arr[i].length() - 1 > 0 ? arr[i].length() - 1 : 0;
//            if (left > 0) {
//                int j = 1;
//                for (; j < arr[i].length(); j ++ ) {
//                    if (arr[i][j] != '0') {
//                        break;
//                    }
//                }
//                if (j == arr[i].length()) {
//                    countZero += j - 1;
//                } else {
//                    result = arr[i];
//                }
//
//            }
//        } else {
//            result = arr[i];
//        }
//    }
//    if (result == "") result = "1";
//    cout << result;
//    for (int i = 0; i < countZero; i ++ ) {
//        cout << 0;
//    }
//    return 0;
//}

#include<iostream>
using namespace std;

int n;
const int N = 100010;

string str[N];
int main(void) {
    scanf("%d", &n);
    int k = 0;
    for (int i = 0; i < n; i ++ ) {
        string s;
        cin >> s;
        str[i] = s;
        if (s == "0") {
            cout << 0 << endl;
            return 0;
        }
        int cnt = 0;
        for (auto c : s) {
            if (c > '1') k = i;
            else if (c == '1') cnt ++;
        }

        if (cnt > 1) {
            k = i;
        }
    }
    cout << str[k];
    for (int i = 0; i < n; i ++ ) {
        if (i != k) {
            cout << str[i].substr(1);
        }
    }
    return 0;
}