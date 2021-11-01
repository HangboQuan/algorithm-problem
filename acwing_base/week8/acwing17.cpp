//
// Created by quanhangbo on 2021/11/1.
//

// https://www.acwing.com/problem/content/18/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> res;
        while(head){
            res.push_back(head -> val);
            head = head -> next;
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};

