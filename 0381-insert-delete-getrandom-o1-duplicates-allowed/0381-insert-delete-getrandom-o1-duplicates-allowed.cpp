class RandomizedCollection {
private:
    vector<pair<int,int>> elements;
    unordered_map<int,vector<int>> indices;
    mt19937 gen;
public:
    RandomizedCollection() : gen(random_device{}()) {}
    
    bool insert(int val) {
        bool flag=indices[val].empty();
        indices[val].push_back(elements.size());
        elements.push_back({val,indices[val].size()-1});
        return flag;   
    }
    
    bool remove(int val) {
        if(indices[val].empty())return false;

        int removePos=indices[val].back();

        auto [lastVal,lastIdx]=elements.back();
        elements[removePos]={lastVal,lastIdx};
        indices[lastVal][lastIdx]=removePos;
        elements.pop_back();
        indices[val].pop_back();
        if(indices[val].empty())indices.erase(val);
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<> dist(0, elements.size()-1); 
        int rn=dist(gen);
        return elements[rn].first;    
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */