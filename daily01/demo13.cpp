//
// Created by quanhangbo on 2021/11/1.
//

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int left = 0;
        int right = array.size() - 1;
        while(left < right){
            //是奇数
            while(left < right && (array[left] & 1) == 1){
                left++;
            }
            //是偶数
            while(left < right && (array[right] & 1) == 0){
                right--;
            }
            cout << left << " " << right;
            cout << "-------";
            swap(array, left, right);
            for(auto a : array){
                cout << a << " ";
            }
            cout << endl;
        }
    }

    void swap(vector<int> &array, int left, int right){
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }


};

int main(void){
    Solution s = Solution();
    vector<int> v = {1, 2, 3, 4, 5};
    s.reOrderArray(v);
}

