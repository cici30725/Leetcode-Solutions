class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = k-1, r = n;
        int cur = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        int best = cur;
        while(r>n-k){
            cur-=cardPoints[l];
            cur+=cardPoints[r-1];
            best = max(best, cur);
            l--;
            r--;
        }
        return best;
    }
};