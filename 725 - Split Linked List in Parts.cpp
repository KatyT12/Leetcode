/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* c = head;
        while(c) {n++; c = c->next;} //Find length of linked list

        int m = n / k; int r = n % k; //Size of parts, plust number of parts with additional 1
        vector<ListNode*> ret = {};
        
        c = head;
        while(k > 0){
            ret.push_back(c);
            int i = m-1; //Size of this partition
            if(r != 0) {i++; r--;}
            k -= 1;
            while(i > 0){c = c->next;i--;}
            if(c){ //Chop end of
                ListNode* temp = c->next;
                c->next = NULL;
                c = temp;
            }   
        }
        return ret;
    }
};