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
    struct Compare {
        bool operator()(ListNode* a,ListNode* b) {
            return a->val > b->val; 
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;  

        for(int i=0;i<lists.size();i++){
            if(lists[i])minHeap.push(lists[i]);
        }
        if(minHeap.empty())return NULL;

        ListNode* head=NULL;
        ListNode* prev=NULL;

        while(!minHeap.empty()){
            ListNode* node=minHeap.top();
            minHeap.pop();
            if(!head)head=node;
            if(prev)prev->next=node;
            if(node->next)minHeap.push(node->next);
            prev=node;
        }




        return head;

    }
};