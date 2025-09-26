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
         vector<int> v(s.begin(), s.end());

        // random generator
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, v.size() - 1);

        return v[dist(gen)];    
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */