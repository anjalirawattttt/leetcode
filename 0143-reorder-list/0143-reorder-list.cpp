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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL,*curr=head,*next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return; 
        //get middle
        ListNode* middle=middleNode(head);
        //separate LL 
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

        
        //reverse second LL 
        head2=reverse(head2);
        //merge them
        temp=NULL;
        while(head1 && head2){
            if(temp){
                temp->next=head1;
                temp=temp->next;
            }
            else{
                temp=head1;
            }
            head1=head1->next;
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;

        }
        if(head1){
            temp->next=head1;
        }

        return;
    }
};