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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        while(k>count){
            k=k%count;
        }

        if(k==count || k==0)return head;

        int length=count-k;

        temp=head;

        while(length>0 && temp){
            prev=temp;
            temp=temp->next;
            length--;
        }
        prev->next=NULL;
        prev=temp;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return prev;
    }
};