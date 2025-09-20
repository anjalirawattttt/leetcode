class Router {
    struct Node{
        int src;
        int dst;
        int ts;
        Node *next,*prev;
        Node(int source, int destination, int timestamp){
            src = source;
            dst = destination;
            ts = timestamp;
            next = nullptr;
            prev = nullptr;
        }
    };
    
    Node* head;
    Node* tail;
    int capacity;
    int size;
    
    unordered_map<int, vector<int>> dts; // destination -> timestamps (sorted)
    unordered_set<long long> packets;    // duplicate check
    
public:
    Router(int memoryLimit) {
        capacity = memoryLimit;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    long long makeKey(int src, int dst, int ts){
        return (long long)src * 1e14 + (long long)dst * 1e9 + ts;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long key = makeKey(source, destination, timestamp);
        if(packets.count(key)) return false; // duplicate
        
        Node* node = new Node(source, destination, timestamp);
        packets.insert(key);
        dts[destination].push_back(timestamp); // always increasing timestamps
        
        if(!head){
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        
        size++;
        
        // LRU eviction
        if(size > capacity){
            Node* temp = head;
            head = head->next;
            if(head) head->prev = nullptr;
            else tail = nullptr;
            
            long long delKey = makeKey(temp->src, temp->dst, temp->ts);
            packets.erase(delKey);
            dts[temp->dst].erase(dts[temp->dst].begin()); // remove oldest timestamp
            if(dts[temp->dst].empty()) dts.erase(temp->dst);
            
            delete temp;
            size--;
        }
        
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> packet;
        if(size == 0) return packet;
        
        packet.push_back(head->src);
        packet.push_back(head->dst);
        packet.push_back(head->ts);
        
        Node* temp = head;
        head = head->next;
        if(head) head->prev = nullptr;
        else tail = nullptr;
        
        long long delKey = makeKey(temp->src, temp->dst, temp->ts);
        packets.erase(delKey);
        dts[temp->dst].erase(dts[temp->dst].begin()); // remove oldest timestamp
        if(dts[temp->dst].empty()) dts.erase(temp->dst);
        
        delete temp;
        size--;
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(dts.find(destination) == dts.end()) return 0;
        auto &vec = dts[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return it2 - it1;
    }
};
