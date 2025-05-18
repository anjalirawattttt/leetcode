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
        if(!node)return ;
        ListNode* temp=node;
        while(temp){
            temp->val=temp->next->val;
            if(!temp->next->next)temp->next=NULL;
            temp=temp->next;
        }
        
    }
};