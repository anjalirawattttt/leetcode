class LRUCache {
    struct Node{
        int key,val;
        Node *prev,*next;
        Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
        }
    };
    unordered_map<int,Node*> m;
    int size=0;
    int cap;
    Node* head=NULL;
    Node* tail=NULL;
public:
    void insertAtBegining(Node* node){
        if(!head){
            head=node;
            tail=node;
            return;
        }
        head->prev=node;
        node->next=head;
        head=node;
    }
    void deleteAtEnd(){
        if(head==tail){
            Node* temp=head;
            m.erase(temp->key);
            head=NULL;
            tail=NULL;
            delete temp;
            return;
        }
        Node* temp=tail;
        m.erase(temp->key);
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
    }
    void moveToFront(Node* temp){
        if(temp==head)return;
        if(temp==tail)tail=tail->prev;
        temp->prev->next=temp->next;
        if(temp->next)temp->next->prev=temp->prev;
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=head->prev;
    }

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        Node* temp=m[key];
        moveToFront(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* temp=m[key];
            temp->val=value;
            moveToFront(temp);
            return;
        }
        Node* node=new Node(key,value);
        m[key]=node;
        insertAtBegining(node);
        // head=node;
        size++;
        if(size>cap){
            deleteAtEnd();
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */