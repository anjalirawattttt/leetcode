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
    ListNode* middleNode(ListNode* head){
        if(!head || !head->next )return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL,*curr =head,*next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;
        //find middle
        ListNode* middle=middleNode(head);
        //reverse second LL
        middle=reverse(middle);
        //compare
        ListNode* head1=head;
        while(head1 && middle){
            if(head1->val!=middle->val)return false;
            head1=head1->next;
            middle=middle->next;
        }
        
        return true;
    }
};