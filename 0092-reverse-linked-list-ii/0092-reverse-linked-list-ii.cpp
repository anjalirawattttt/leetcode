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
        ListNode* prev=NULL,*curr=head,*next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next ||left==right)return head;
        //find left and right node
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* prev=dummy,*next;
        for(int i=1;i<=left-1;i++){
            prev=prev->next;
        }
        ListNode* start,*end;
        start=prev->next;
        end=start;
        for(int i=left;i<=right-1;i++){
            end=end->next;
        }
        next=end->next;
        end->next=NULL;
        prev->next=reverse(start);
        while(start->next){
            start=start->next;
        }
        start->next=next;

        return dummy->next;

    }
};