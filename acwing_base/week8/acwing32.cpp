//
// Created by quanhangbo on 2021/11/1.
//

// https://www.acwing.com/problem/content/30/
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
            while(left < right && (array[right] & 1) == 0){
                right--;
            }
            swap(array, left, right);
        }
    }

    void swap(vector<int> &array, int left, int right){
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
};

