class Solution {
public:
    int longestPalindrome(string s) {
        int flag = false;
        unordered_map<int, int> freq;
        for(char c : s)
            freq[c]++;
        
        int res = 0;
        for(auto& [_, i] : freq){
            if(i%2==0){
                res += i;
            }
            else if(i>1){
                res += (i-1);
                flag = true;
            }
            else{
                flag = true;
            }
        }
        
        return res + (flag ? 1 : 0);
    }
};