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
        //separate LL
        ListNode* head1=head;
        ListNode* head2=middle;
        ListNode* temp=head,*prev;
        while(temp){
            if(temp==middle){
                prev->next=NULL;
            }
            prev=temp;
            temp=temp->next;
        }
        //reverse second LL
        head2=reverse(head2);
        //compare  
            while(head1 && head2){
                if(head1->val!=head2->val)return false;
                head1=head1->next;
                head2=head2->next;
            }
        
        return true;
    }
};