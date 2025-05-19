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
    ListNode* add(ListNode* l1,ListNode* l2){
        if(l1==NULL && l2==NULL)return NULL;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        int carry=0;
        ListNode* t1=l1,*t2=l2,*prev=NULL;
            while(t2){
                int sum=t1->val+t2->val+carry;
                t1->val=sum%10;
                carry=sum/10;
                prev=t1;
                t1=t1->next;
                t2=t2->next;
            }
            while(t1){
                int sum=t1->val+carry;
                t1->val=sum%10;
                carry=sum/10;
                prev=t1;
                t1=t1->next;
            }
            if(carry!=0)prev->next=new ListNode(carry);
            return l1;        
    }
    int size(ListNode* head){
        if(!head)return 0;
        int count=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }

    ListNode* reverse(ListNode* head){
        if(!head || !head->next)return head;
        ListNode* prev=NULL; 
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)return NULL;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        l1=reverse(l1);
        l2=reverse(l2);
        int s1=size(l1);
        int s2=size(l2);
        if(s1>=s2){
            l1=add(l1,l2);
            l1=reverse(l1);
            return l1;
        }
        else{
            l2=add(l2,l1);
            l2=reverse(l2);
            return l2;
        }
        
    }
};