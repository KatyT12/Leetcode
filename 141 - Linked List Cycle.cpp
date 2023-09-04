
//Need O(1) memory

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
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;
        while(curr){
            curr->val = 10001;
            if(curr->next && curr->next->val == 10001){
                return true;
            }else{
                curr = curr->next;
            }
        }
        return false;
    }
};