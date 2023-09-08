class RandomizedSet {
public:
    unordered_map<int, int> indices;
    vector<int> values;
    
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(indices.find(val)!=indices.end())
            return false;
        values.push_back(val);
        indices[val] = values.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(indices.find(val)==indices.end())
            return false;
        int idx = indices[val];
        int last_val = values[values.size()-1];
        swap(values[values.size()-1], values[idx]);
        values.pop_back();
        indices[last_val] = idx;
        
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */