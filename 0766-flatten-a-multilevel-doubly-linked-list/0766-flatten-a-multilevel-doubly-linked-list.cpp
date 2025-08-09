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
                Node* childTail=flattenDFS(curr->child);
                curr->next=curr->child;
                curr->child->prev=curr;
                curr->child=NULL;
                childTail->next=next;
                if(next)next->prev=childTail;
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