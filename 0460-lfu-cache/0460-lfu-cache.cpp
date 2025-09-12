class LFUCache {
    struct Node{
        int key,val,freq;
        Node* prev,*next;
        Node(int k,int v){
            key=k;
            val=v;
            freq=1;
            prev=next=NULL;
        }
    };
    int size=0;
    int cap;
    unordered_map<int,Node*> m;//maps key to node
    unordered_map<int,pair<Node*,Node*>> freq;//maps a given freq to doubly linked list (head,tail)
    int minFreq=0;
public:
    void insert(int f,Node* node){
        if(freq.find(f)==freq.end()){
            freq[f]={node,node};
            return;
        }
        Node* head=freq[f].first;
        head->prev=node;
        node->next=head;  
        freq[f].first=node;      
    }
    //check again
    void deletefrommin(){
        Node* head=freq[minFreq].first;
        Node* tail=freq[minFreq].second;
        int k=tail->key;
        if(head==tail){
            freq.erase(minFreq);
        }
        else{
            freq[minFreq].second=tail->prev;
            tail->prev->next=NULL;
        }
        m.erase(k);
        delete tail;
    }

    void deletenode(int f,Node* node){
        Node* head=freq[f].first;
        Node* tail=freq[f].second;
        if(head==node && tail==node){
            freq.erase(f);
        } 
        else if(node==head){
            freq[f].first=head->next;
            head->next->prev=NULL;
        }
        else if(node==tail){
            freq[f].second=tail->prev;
            tail->prev->next=NULL;
        }
        else{
            node->prev->next=node->next;
            node->next->prev=node->prev;
        }
    }

    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        Node* temp=m[key];
        deletenode(temp->freq,temp);
        if(freq.find(temp->freq)==freq.end() && temp->freq==minFreq)minFreq++;
        temp->prev=NULL;
        temp->next=NULL;
        temp->freq++;
        insert(temp->freq,temp);
        m[key]=temp;
        return temp->val;
    }
    
    void put(int key, int value) {
        //if already present
        if(m.find(key)!=m.end()){
            Node* temp=m[key];
            temp->val=value;
            deletenode(temp->freq,temp);
            if(freq.find(temp->freq)==freq.end() && temp->freq==minFreq)minFreq++;
            temp->prev=NULL;
            temp->next=NULL;
            temp->freq++;
            insert(temp->freq,temp);
            m[key]=temp;
            return;
        }
        //if not already present
        if(size==cap){
            deletefrommin();
            size--;
        }

        Node* node=new Node(key,value);
        minFreq=1;
        insert(1,node);
        m[key]=node;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */