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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* prev=head;
        ListNode* temp=head->next;
        ListNode* headStart=head->next;
        ListNode* next=NULL;
        while(prev){
            if(temp)next=temp->next;
            else next=NULL;
            if(temp)temp->next=prev;
            if(next && next->next)prev->next=next->next;
            else prev->next=next;
            prev=next;
            if(next)temp=next->next;
        }
        return headStart;

    }
};