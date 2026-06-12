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
    int findSize(ListNode* head){
        int size=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            size++;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;

        int size = findSize(head);
        k = k % size;

        if(k==0)return head;

        ListNode* right = head;
        for(int i=0;i<k;i++){
            right = right -> next;
        }

        ListNode* prev = nullptr;
        ListNode* left = head; 
        while(right){
            prev=left;
            left=left->next;
            right=right->next;
        }

        prev->next = nullptr;

        right=left;
        while(right->next){
            right=right->next;
        }

        right->next=head;
        return left;

         
        
    }
};