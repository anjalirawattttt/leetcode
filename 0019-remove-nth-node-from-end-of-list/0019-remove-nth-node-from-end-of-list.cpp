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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        int size=0;
        while(temp){
            temp=temp->next;
            size++;
        }

        if(n==size){
            head=head->next;
            return head;
        }

        int del=size-n;
        
        size=0;
        temp=head;
        while(temp){
            prev=temp;
            temp=temp->next;
            size++;
            if(size==del){
                prev->next=temp->next;
                break;
            }
        }
        return head;       

    }
};