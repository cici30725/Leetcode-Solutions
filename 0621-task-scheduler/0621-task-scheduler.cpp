class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char c : tasks)
            freq[c-'A']++;
        
        sort(freq.begin(), freq.end());
        
        int max_f = freq[freq.size()-1];
        int idle_slots = (max_f-1) * n;
        for(int i=freq.size()-2; i>=0; i--){
            idle_slots -= min(max_f-1, freq[i]) ;
        }
        
        return idle_slots < 0 ? tasks.size() : tasks.size() + idle_slots;
    }
};