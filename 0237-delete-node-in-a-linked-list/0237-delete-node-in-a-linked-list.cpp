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
    void deleteNode(ListNode* node) {
        ListNode* prev=node;    
        ListNode* curr=node->next;
        swap(prev->val,curr->val);

        while(curr->next){
            prev=prev->next;
            curr=curr->next;
            swap(prev->val,curr->val);
        } 
        prev->next=NULL;
        delete curr; 
    }
};