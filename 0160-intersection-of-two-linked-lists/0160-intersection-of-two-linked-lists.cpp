/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)return NULL;
        int a=0,b=0;
        ListNode* tempA=headA;   
        ListNode* tempB=headB;  
        while(tempA){
            a++;
            tempA=tempA->next;
        }
        while(tempB){
            b++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;

        if(a<=b){
            for(int i=0;i<(b-a);i++){
                tempB=tempB->next;   
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;   
            }
            return tempA;
        }
        for(int i=0;i<(a-b);i++){
            tempA=tempA->next;   
        }
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;   
        }
        return tempA;
    }
};