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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)return head;
        ListNode* head1=NULL;    
        ListNode* head2=NULL; 
        ListNode* l1=NULL;    
        ListNode* l2=NULL; 
        ListNode* temp=head; 
        while(temp){
            if(temp->val<x){
                if(!l1){
                    head1=temp;
                    l1=temp;
                }
                else{
                    l1->next=temp;
                    l1=l1->next;
                }
            }
            else{
                if(!l2){
                    head2=temp;
                    l2=temp;
                }
                else{
                    l2->next=temp;
                    l2=l2->next;
                }
            }
            temp=temp->next;
        }  
        if(!head1 || !head2)return head1?head1:head2;
        l1->next=head2;
        l2->next=NULL;
        return head1;
    }
};