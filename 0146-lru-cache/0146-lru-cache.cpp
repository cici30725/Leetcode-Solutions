class LRUCache {
public:
    int cap;
    using pii = pair<int, int>;
    unordered_map<int, list<pii>::iterator> m_map;
    list<pii> m_list;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m_map.find(key);
        if(it==m_map.end())
            return -1;
        
        m_list.splice(m_list.begin(), m_list, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m_map.find(key);
        if(it!=m_map.end()){
            it->second->second = value;
            m_list.splice(m_list.begin(), m_list, it->second);
            return;
        }
        
        if(m_map.size() == cap){
            int key_to_remove = m_list.back().first;
            m_list.pop_back();
            m_map.erase(key_to_remove);
        }
        
        m_list.emplace_front(key, value);
        m_map[key] = m_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */