class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sol = 0;
        for(char c : columnTitle){
            sol *= 26;
            sol += c-'A'+1;
        }
        return sol;
    }
};