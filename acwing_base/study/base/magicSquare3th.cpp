//
// Created by quanhangbo on 2023/3/12 20:47.
//

#include<iostream>
#include<vector>
using namespace std;
int total = 0;

void dfs(int step, vector<long>& record, bool st[10], vector<long>& vec) {
    if (step == vec.size()) {
//            if (record[0] == 9 && record[1] == 2 && record[2] == 7 && record[3] == 4) {
//                for(int i = 0; i < record.size(); i ++ ) {
//                    cout << record[i] << " ";
//                }
//                cout << endl;
//            }

        for(int i = 0; i < record.size(); i ++ ) {
            cout << record[i] << " ";
        }
        cout << endl;

//        int arr[3][3];
//        arr[0][0] = record[0];
//        arr[0][1] = record[1];
//        arr[0][2] = record[2];
//        arr[1][0] = record[3];
//        arr[1][1] = record[4];
//        arr[1][2] = record[5];
//        arr[2][0] = record[6];
//        arr[2][1] = record[7];
//        arr[2][2] = record[8];
//
//        int num = 18;
//        if(arr[0][0] + arr[0][1] + arr[0][2] == num && arr[1][0] + arr[1][1] + arr[1][2] == num &&
//        arr[2][0] + arr[2][1] + arr[2][2] == num && arr[0][0] + arr[1][0] + arr[2][0] == num && arr[0][1] +
//        arr[1][1] + arr[2][1] == num && arr[0][2] + arr[1][2] + arr[2][2] == num &&
//        arr[0][0] + arr[1][1] + arr[2][2] == num && arr[0][2] + arr[1][1] + arr[2][0] == num) {
//            for(int i = 0; i < 3; i ++ ) {
//                for(int j = 0; j < 3; j ++ ) {
//                    cout << arr[i][j] << " ";
//                }
//                cout << endl;
//            }
//            total ++;
//            cout << endl;
//        }
        total ++;
        return ;
    }

    for(int i = 0; i < vec.size(); i ++ ) {
        if (!st[i]) {
            st[i] = true;
            record.push_back(vec[i]);
            dfs(step + 1, record, st, vec);
            st[i] = false;
            record.pop_back();
        }
    }
}
int main(void) {
    // 1~9的全排列
    vector<long> vec = {1L, 2L, 3L, 4L, 5L, 6L, 7L, 8L, 9L, 10L, 11L};
//    vector<int> vec = {1, 2, 3};
    vector<long> record;
    bool st[10];
    dfs(0, record, st, vec);
    // result: 9!=362280
    cout << total << endl;
}
