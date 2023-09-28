class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        while(i>=0 || j>=0){
            int iBackCount = 0;
            while(i>=0){
                if(s[i]=='#')
                    iBackCount++;
                else
                    iBackCount--;
                if(iBackCount<0)
                    break;
                i--;
            }
            
            int jBackCount = 0;
            while(j>=0){
                if(t[j]=='#')
                    jBackCount++;
                else
                    jBackCount--;
                if(jBackCount<0)
                    break;
                j--;
            }
            
            if(j>=0 && i>=0 && s[i]!=t[j])
                return false;
            
            if((j>=0)!=(i>=0))
                return false;
            
            i--;
            j--;
        }
        
        return true;
    }
};