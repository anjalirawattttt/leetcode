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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* temp=head;
        ListNode* prev=head;
        int num=head->val;
        while(temp){
           while(temp && temp->val==num){
            temp=temp->next;
           } 
           prev->next=temp;
           if(temp)num=temp->val;
           prev=temp;

        }
        return head;
    }
};