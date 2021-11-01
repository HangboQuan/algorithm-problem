//
// Created by quanhangbo on 2021/11/1.
//

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

//vector<int> printListReversingly(ListNode* head) {
//    ListNode* h;
//    int cnt = 0;
//    for(ListNode* p = head; p != NULL; p = p -> next){
//        p -> next = h;
//        h = p;
//        cnt ++;
//    }
//    vector<int> v ;
//    for(ListNode* p = h; p != NULL; p = p -> next){
//        v.push_back(p -> val);
//    }
//    return v;
//}

int main(void){
    vector<int> v;
    for(int i = 1; i <= 5; i ++ ){
        v.push_back(i);
    }
    for(int i = 1; i <= 5; i ++ ){
        cout << i << " ";
    }
    cout << endl;
}

