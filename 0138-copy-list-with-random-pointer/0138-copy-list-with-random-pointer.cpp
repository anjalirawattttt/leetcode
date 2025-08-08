/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        
        //create new nodes
        Node* temp=head;
        while(temp){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }  

        //assign random pointers
        temp=head;
        while(temp){
            if(temp->random)temp->next->random=temp->random->next;
            temp=temp->next->next;

        }

        //separate old and new lists
        temp=head;
        Node* newHead=head->next;
        while(temp){
            Node* copy=temp->next;
            temp->next=temp->next->next;
            if(copy->next)copy->next=copy->next->next;
            temp=temp->next;
        }
        return newHead;


    }
};