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
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int a = 0 , b = 0;

        while(tempA != tempB){
            tempA = tempA->next ;
            tempB = tempB->next ;
            if(!tempA){
                tempA = headB;
                a++;
            } 
            if(!tempB){
                tempB = headA;
                b++;
            }
            if( a>1 || b>1 )break;
        }

        if(a>1 || b>1)return nullptr;

        return tempA;        
    }
};