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
        ListNode* prev=NULL;
        while(temp){
            while(temp && temp->next && temp->val==temp->next->val){
                int x=temp->val;
                while(temp && temp->val==x){
                    temp=temp->next;
                }
            }
            if(!prev){
                head=temp;
                prev=temp;
                if(temp)temp=temp->next;
            }
            else{
                prev->next=temp;
                prev=temp;
                if(temp)temp=temp->next;
            }            
        }
        return head;
    }
};