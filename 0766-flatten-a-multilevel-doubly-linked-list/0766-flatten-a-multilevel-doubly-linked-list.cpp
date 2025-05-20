/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattenDFS(Node* node){
        Node* curr=node;
        Node* last=NULL;

        while(curr){
            Node* next=curr->next;
            if(curr->child){
                Node* child=curr->child;
                Node* childTail=flattenDFS(child);

                curr->next=child;
                child->prev=curr;

                if(next){
                    childTail->next=next;
                    next->prev=childTail;
                }
                curr->child=NULL;
                last=childTail;
            }
            else{
                last=curr;
            }
            curr=next;
        }
        return last;
        
    }

    Node* flatten(Node* head) {
        if(!head)return head;
        flattenDFS(head);
        return head;
    }
};