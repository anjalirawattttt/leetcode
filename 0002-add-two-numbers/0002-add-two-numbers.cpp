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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2; 
        int sum = 0 , carry = 0;

        ListNode* dummy = new ListNode() ;
        ListNode* tail = nullptr ;

        while(temp1 && temp2){
            int x=temp1->val + temp2->val + carry ;
            sum = x % 10 ;
            carry = x / 10 ;
            if(!tail){
                dummy->next = new ListNode(sum) ;
                tail = dummy->next;
            }
            else{
                tail->next = new ListNode(sum) ;
                tail = tail->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 ){
            int x = temp1->val + carry ;
            sum = x % 10 ;
            carry = x / 10 ;
            tail->next = new ListNode(sum) ;
            tail = tail->next;
            temp1 = temp1->next;
        }

        while(temp2){
            int x = temp2->val + carry ;
            sum = x % 10 ;
            carry = x / 10 ;
            tail->next = new ListNode(sum) ;
            tail = tail->next;
            temp2 = temp2->next;
        }
        
        if(carry){
            tail->next = new ListNode(carry) ;
            tail = tail->next;
        }

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};