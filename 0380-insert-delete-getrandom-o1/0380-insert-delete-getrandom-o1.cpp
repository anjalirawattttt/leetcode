class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {
            
    }
    
    bool insert(int val) {
        if(s.count(val))return false;
        s.insert(val); 
        return true;   
    }
    
    bool remove(int val) {
        if(!s.count(val))return false;
        s.erase(val);  
        return true;  
    }
    
    int getRandom() {
         auto it = s.begin();    
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(0, s.size() - 1);
            int x = dist(gen);

            advance(it, x);   
            return *it;    
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */