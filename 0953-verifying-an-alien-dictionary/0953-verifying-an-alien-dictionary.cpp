class Solution {
public:
    vector<int> ord = vector<int>(26);
    bool smaller(string& a, string& b){
        for(int i=0; i<a.size(); i++){
            if(i>=b.size())
                return false;
            if(ord[a[i]-'a']<ord[b[i]-'a']){
                return true;
            }
            else if(ord[a[i]-'a']>ord[b[i]-'a']){
                return false;
            }
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<26; i++){
            ord[order[i]-'a'] = i;
        }
        
        for(int i=0; i<words.size()-1; i++){
            if(!smaller(words[i], words[i+1]))
                return false;
        }
        return true;
    }
};