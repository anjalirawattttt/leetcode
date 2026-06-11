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
        ListNode* nth = head ; 
        for(int i = 0 ; i < n ; i++){
            nth = nth->next ;
        }  
        ListNode* temp = head;
        ListNode* prev = nullptr ;
        while(nth){
            prev = temp;
            temp = temp->next;
            nth = nth->next;
        }

        if(!prev){
            //head
            prev = temp ;
            temp = temp->next;
            delete prev ;
            return temp ;
        } 

        prev->next = temp->next ;
        delete temp;
        return head;
    }
};