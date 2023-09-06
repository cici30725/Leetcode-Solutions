class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        vector<int> count(26);
        int non_zero = 0;
        for(char c : s1){
            if(count[c-'a']==0) 
                non_zero++;
            count[c-'a']++;
        }
        
        for(int i=0; i<s1.size(); i++){
            char c = s2[i];
            count[c-'a']--;
            if(count[c-'a']==0)
                non_zero--;
            else if(count[c-'a']==-1)
                non_zero++;
        }
        
        if(non_zero == 0)
            return true;
        
        int l = 0, r = s1.size();
        while(r<s2.size()){
            char r_c = s2[r], l_c = s2[l];
            count[r_c-'a']--;
            if(count[r_c-'a']==0)
                non_zero--;
            else if(count[r_c-'a']==-1)
                non_zero++;
                
            count[l_c-'a']++;
            if(count[l_c-'a']==0)
                non_zero--;
            else if(count[l_c-'a']==1)
                non_zero++;
                
            if(non_zero==0)
                return true;
            
            l++;
            r++;
        }
        
        return false;
        
        
    }
};