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
    ListNode* findK(int k,ListNode* node){
        if(!node)return nullptr;

        ListNode* temp=node;
        for(int i=0;i<k-1;i++){
            temp=temp->next;
            if(!temp)return temp;
        }
        return temp;
    }

    void reverse(ListNode* start){
        ListNode* prev=nullptr;
        ListNode* curr=start;
        ListNode* next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        // return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return nullptr;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;

        ListNode* temp = head;
        ListNode* kth = findK(k,temp); 
        ListNode* newHead = nullptr; 
        
        while(kth){  
            if(!newHead){
                newHead = kth;
            }      

            nextNode = kth->next;
            kth->next = nullptr;
            reverse(temp);

            if(prevNode)prevNode->next = kth;

            temp->next = nextNode;
            prevNode = temp;

            temp = temp->next ;
            kth = findK(k,temp); 
        }

        return newHead;
    }
};