class LFUCache {
public:
    using Node = pair<int, int>;
    list<pair<int, list<Node>>> freq; // [<freq, [Node...]>]
    unordered_map<int, pair<list<pair<int, list<Node>>>::iterator, list<Node>::iterator>> key_to_node; // <key, node ieterator>
    int cap;
    
    LFUCache(int capacity): cap{capacity} {
        
    }
    
    void getNode(int key, int value) {
        if(key_to_node.find(key)==key_to_node.end()){
            if(key_to_node.size()+1 > cap){
                // cout<<"here "<<key<<endl;
                auto& [_, min_freq_list] = *(freq.begin());
                auto node_it = min_freq_list.begin();
                auto node_key = node_it->first;
                // cout<<node_key<<endl;
                
                // Clear key 
                key_to_node.erase(node_key);
                
                // Erase node from list
                min_freq_list.erase(node_it);
                
                // If list is empty, remove it
                if(min_freq_list.empty())
                    freq.pop_front();
            }
            
            auto freq_list_it = freq.begin();
            // If freq is empty or the first freq is greater than 1
            if(freq_list_it==freq.end() || freq_list_it->first > 1){
                freq.emplace_front(1, list<Node>{{key, value}});
            }
            else{
                auto& list_head = freq_list_it->second;
                list_head.emplace_back(key, value);
            }
            key_to_node[key] = {freq.begin(), --(freq.begin()->second.end())};
            // return key_to_node[key];
        }
        else{
            auto& [list_head_it, node_it] = key_to_node[key];
            int prev_freq = list_head_it->first;
            (list_head_it->second).erase(node_it);
            auto prev_list_head_it = list_head_it;
            list_head_it++;
            
            if(list_head_it!=freq.end() && list_head_it->first == prev_freq+1){
                // Has next_freq;
                (list_head_it->second).emplace_back(key, value);
                key_to_node[key] = {list_head_it, --(list_head_it->second.end())};
            }
            else{
                // Does not have next freq
                auto inserted_it = freq.insert(list_head_it, {prev_freq+1, list<Node>{{key, value}}});
                key_to_node[key] = {inserted_it, inserted_it->second.begin()};
            }
            
            // Remove previous freq_list if empty after erase
            if(prev_list_head_it->second.empty())
                freq.erase(prev_list_head_it);
            
            // return key_to_node[key]->second;
        }
        
    }
    
    int get(int key) {
        if(key_to_node.find(key)==key_to_node.end())
            return -1;
        auto& [freq_list_it, node_it] = key_to_node[key];
        int value = node_it->second;
        getNode(key, value);
        return value;
        // freq_list_it->second.splice(freq_list_it->second.end(), freq_list_it->second, node_it);
        // return val;
    }
    
    void put(int key, int value) {
        getNode(key, value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */