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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)return NULL;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp;
        ListNode* head=NULL;

        while( temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                if(head==NULL){
                    head=temp1;
                    temp=head;
                }
                else{
                    temp->next=temp1;
                    temp=temp->next;
                }
                temp1=temp1->next;
            }
            else{
                if(head==NULL){
                    head=temp2;
                    temp=head;
                }
                else{
                    temp->next=temp2;
                    temp=temp->next;
                }
                temp2=temp->next;                
            }
        }
        while( temp1!=NULL ){
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }
        while( temp2!=NULL){
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
        return head;


    }
};