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
    ListNode* findK(ListNode* node,int k){
        for(int i=0;i<k-1;i++){
            if(node)node=node->next;
            else return NULL;
        }
        return node;
    }

    void reverse(ListNode* head){
        if(!head || !head->next)return;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(next)next=next->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)return head;

        ListNode* prevNode=NULL;
        ListNode* nextNode=NULL;
        ListNode* temp=head;

        while(temp){
            ListNode* kthNode=findK(temp,k);

            if(!kthNode){
                if(prevNode)prevNode->next=temp;
                break;
            }

            nextNode=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);

            if(temp==head)head=kthNode;
            if(prevNode)prevNode->next=kthNode;
            prevNode=temp;

            temp=nextNode;

        }
        return head;
        

    }
};