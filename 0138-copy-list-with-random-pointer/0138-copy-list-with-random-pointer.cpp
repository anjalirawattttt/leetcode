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
        Node* temp=NULL;
        if(!head)return temp;
        temp=head;
        //Adding clones
        while(temp){
            Node* node=new Node(temp->val);
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
        //setting random pointers
        temp=head;
        while(temp){
            if(!temp->random){
                temp->next->random=NULL;
                temp=temp->next->next;
            }
            else{
                temp->next->random=temp->random->next;
                temp=temp->next->next;
            }            
        }
        //separating lists
        temp=head;
        Node* newHead=head->next;
        Node* temp2=newHead;
        while(temp2){
            temp->next=temp2->next;
            temp=temp->next;
            if(temp)temp2->next=temp->next;
            temp2=temp2->next;
        }
        return newHead;
    }
};