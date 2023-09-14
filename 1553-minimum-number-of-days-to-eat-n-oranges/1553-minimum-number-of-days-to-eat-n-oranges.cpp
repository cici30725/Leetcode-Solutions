class Solution {
public:
    int minDays(int n) {
        queue<pair<int, int>> q;
        unordered_set<int> visit;
        q.push({n, 0});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int num = cur.first, len = cur.second;
            if(num==0)
                return len;
            if(visit.find(num)!=visit.end())
                continue;
            visit.insert(num);
            q.push({num-1, len+1});
            if(num%2==0)
                q.push({num/2, len+1});
            if(num%3==0)
                q.push({num - 2*(num/3), len+1});
        }
        return -1;
    }
};