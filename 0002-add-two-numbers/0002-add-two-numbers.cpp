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
    void help(ListNode* l1, ListNode* l2){
        ListNode* s=l1;
        ListNode* l=l2;

        int n,carry=0;
        while(s){
            n=s->val + l->val + carry;
            carry=n/10;
            l->val=n%10;
            s=s->next;
            l=l->next;
        }
        while(carry){
            if(l){
                n=l->val+carry;
                carry=n/10;
                l->val=n%10; 
                l=l->next;   
            }
            else{
                ListNode* node=new ListNode(carry);
                ListNode* temp=l2;
                while(temp->next){
                    temp=temp->next;
                }
                temp->next=node;
                carry=0;               
            }   
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2)return l1 ? l1 : l2;

        int a1=0,a2=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1){
            a1++;
            temp1=temp1->next;
        }
        while(temp2){
            a2++;
            temp2=temp2->next;
        }

        if(a1<=a2){
            help(l1,l2);
        }
        else{
            help(l2,l1);
        }

        //temp2 is larger one
        if(a1<=a2){
            return l2;
        }
        return l1;
    }
};