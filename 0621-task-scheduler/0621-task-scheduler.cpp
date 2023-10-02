class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> freq{};
        for(char c : tasks){
            freq[c-'A']++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // freq, task
        queue<pair<int, int>> q; // time, task
        for(int i=0; i<26; i++){
            if(freq[i] > 0)
                pq.push({freq[i], i});
        }
        
        int cur_time = 0;
        while(!pq.empty() || !q.empty()){
            while(!q.empty() && q.front().first <= cur_time){
                auto [time, task]  = q.front();
                pq.push({freq[task], task});
                q.pop();
            }
            
            if(!pq.empty()){
                auto [cur_freq, task] = pq.top();
                pq.pop();
                if(--freq[task] > 0)
                    q.push({cur_time + n + 1, task});
            }
            cur_time++;
        }
        
        return cur_time;
    }
};