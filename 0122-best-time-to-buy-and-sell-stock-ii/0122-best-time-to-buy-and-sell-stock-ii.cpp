class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_sum = 0;;
        int res = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                cur_sum += prices[i]-prices[i-1];
            }
            else{
                res += cur_sum;
                cur_sum = 0;
            }
        }
        
        res += cur_sum;
        return res;
    }
};