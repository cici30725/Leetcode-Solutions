class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool positive = true;
        int i = 0;
        while(s[i]==' ')
            i++;
        
        if(i< n && s[i]=='-'){
            positive = false;
            i++;
        }
        else if(i<n && s[i]=='+'){
            positive = true;
            i++;
        }
        
        int res = 0;
        while(i<n && isdigit(s[i])){
            int last = s[i]-'0';
            if(positive){
                if(INT_MAX/10 < res || (INT_MAX/10 == res && last >= 7)){
                    return INT_MAX;
                }
                else{
                    res*=10;
                    res += last;
                }
            }
            else{
                if(INT_MIN/10 > res || (INT_MIN/10 == res && last >= 8)){
                    return INT_MIN;
                }
                else{
                    res*=10;
                    res -= last;
                }
            }
            i++;
        }
        
        return res;
    }
};