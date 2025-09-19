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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head->next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* findMiddle(ListNode* head){
        if(!head)return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return ;
        //find middle
        //returns one before middle
        ListNode* middle=findMiddle(head);
        //break the LL into 2 parts
        ListNode* head1=head;
        ListNode* head2=middle;
        ListNode* temp=head;
        while(temp){
            if(temp->next==middle){
                temp->next=NULL;
                break;
            }
            temp=temp->next;
        }
        //Reverse the second part
        head2=reverse(middle);
        //connect both LL
        ListNode* temp1=head1;
        ListNode* temp2=head2;

        while(head1 && head2){
            temp1=head1->next;
            head1->next=head2;
            temp2=head2->next;
            if(temp1)head2->next=temp1;
            head1=temp1;
            head2=temp2;
        }
        
    }
};