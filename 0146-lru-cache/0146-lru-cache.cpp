class LRUCache {
public:
    typedef struct Node{
        int key,value;
        Node* prev,*next;
        Node(int k,int v){
            key=k;
            value=v;
            prev=NULL;
            next=NULL;
        }

    }Node;

    int capacity;
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;

    void insert(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }

    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        Node* node=m[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            remove(m[key]);
            delete(m[key]);
        }

        Node* node=new Node(key,value);
        insert(node);
        m[key]=node;
        if(m.size()>capacity){
            Node* lru=tail->prev;
            remove(lru);
            m.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */