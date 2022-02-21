//
// Created by quanhangbo on 2022/2/20 16:05.
//

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

string repeatLimitedString(string s, int k){
    unordered_map<int, int> freq;
    for(char ch : s){
        freq[ch] ++;
    }

    string ans;
    for(char ch = 'z'; ch >= 'a'; ch -- ){
        for(int i = 0; i < freq[ch]; i ++ ){
            ans.push_back(ch);
        }
    }

    int cnt = 1;
    for(int left = 1, right = 2; left < s.size(); left ++ ){
        if(ans[left] != ans[left - 1]){
            cnt = 1;
        }else{
            cnt ++;
            if(cnt > k){
                right = max(right, left + 1);
                while(right < s.size() && ans[left] == ans[right]){
                    right ++;
                }
                if(right < s.size()){
                    swap(ans[left], ans[right]);
                    cnt = 1;
                }else{
                    // right == s.size() 有多余的元
                    cout << left << endl;
                    ans.erase(ans.begin() + left, ans.end());
                    break;
                }
            }
        }
    }

    return ans;
}
int main(void){
    cout << repeatLimitedString("bbbaaaa", 2);

}