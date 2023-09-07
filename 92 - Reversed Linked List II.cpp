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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* s = head; ListNode* curr = head; ListNode* l = head;
        // Find left node and node previous to it
        if(left == 1){l = head, s = NULL;}
        else{
            for(int i = 2; i < left; i++)
                s = s->next;
            l = s->next;
        }
        
        //Reverse sub-list
        ListNode* prev = l; curr = l->next; 
        for(int i = left; i < right; i++){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        //Deal with loose ends
        ListNode* r = prev;
        if(s){s->next = r;}
        l->next = curr;
        
        //If left = head then the head has changed to the end of the sublist
        if(left != 1) return head;
        else return r;
    }
};