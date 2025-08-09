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
        if( !head || !head->next )return head;  

        //count nodes
        int n=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            n++;
        }

        if(k>=n){
            k=k%n;
        }

        if(k==0)return head;


        //move temp n-k ahead;
        temp=head;     
        ListNode* prev=NULL;   
        for(int i=0;i<n-k;i++){
            prev=temp;
            temp=temp->next;
        }
        if(prev)prev->next=NULL;

        ListNode* newHead=temp;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return newHead;
    }
};