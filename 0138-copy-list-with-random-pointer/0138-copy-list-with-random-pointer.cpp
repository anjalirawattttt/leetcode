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
        if(!head)return nullptr;

        Node* temp = head ;
        Node* next=nullptr;
        //duplicate
        while(temp){
            next = temp->next;
            Node* newNode = new Node( temp->val );
            temp->next = newNode;
            newNode->next = next;
            temp=next;
        } 

        //set random pointer
        temp=head;
        while(temp){
            if(temp->random)temp->next->random = temp->random->next;
            else temp->next->random = nullptr; 
            temp = temp->next->next;
        }

        //separate lists
        Node* newHead=head->next;
        Node* tail=nullptr;
        Node* newTail=nullptr;
        temp=head;
        while(temp){
            next=temp->next->next;
            if(!tail){
                tail=temp;
            }
            else{
                tail->next=temp;
                tail=tail->next;
            }

            if(!newTail){
                newTail=temp->next;
            }
            else{
                newTail->next=temp->next;
                newTail=newTail->next;
            }
            temp=next;
        } 
        tail->next=nullptr;
        newTail->next=nullptr;

        return newHead;


    }
};