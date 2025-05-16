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
        ListNode* a=l1;
        ListNode* b=l2;
        int c1=0;
        int c2=0;
        while(a){
            a=a->next;
            c1++;
        }
        while(b){
            b=b->next;
            c2++;
        }
        a=l1;
        b=l2;
        ListNode* prev;
        int carry=0,num;
        if(c1>=c2){
            while(a && b){
                int x=a->val + b->val+carry;
                num=x%10;
                carry=x/10;
                a->val=num;
                prev=a;
                a=a->next;
                b=b->next;
            }
            while(a){
                int x=a->val+carry;
                num=x%10;
                carry=x/10;
                a->val=num;
                prev=a;
                a=a->next;
            }
            if(carry!=0){
                prev->next=new ListNode(carry);
            }
            return l1;

        }
        else{
            while(a && b){
                int x=a->val + b->val+carry;
                num=x%10;
                carry=x/10;
                b->val=num;
                a=a->next;
                prev=b;
                b=b->next;
            }
            while(b){
                int x=b->val+carry;
                num=x%10;
                carry=x/10;
                b->val=num;
                prev=b;
                b=b->next;
            }
            if(carry!=0){
                prev->next=new ListNode(carry);
            }
            return l2;

        }
        
    }
};