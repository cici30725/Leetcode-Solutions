class LRUCache {
public:
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int m_cap;
        
    LRUCache(int capacity): m_cap{capacity} {
        
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        auto& it = cache[key];
        data.splice(data.begin(), data, it);
        return data.begin()->second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            auto& it = cache[key];
            it->second = value;
            data.splice(data.begin(), data, it);
            return;
        }
            
        data.push_front({key, value});
        cache[key] = data.begin();
        
        if(data.size() > m_cap){
            int removeKey = data.back().first;
            data.pop_back();
            cache.erase(removeKey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */