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
    struct cmp{
        bool operator()( ListNode* a, ListNode* b)const{
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode* , vector<ListNode* > , cmp > pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])pq.push(lists[i]);
        }  
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(!pq.empty()){
            if(!head){
                head=pq.top();
                pq.pop();
                temp=head;
            }
            else{
                temp->next=pq.top();
                pq.pop();
                temp=temp->next;
            }
            if(temp->next)pq.push(temp->next);
        }
        return head;
    }
};