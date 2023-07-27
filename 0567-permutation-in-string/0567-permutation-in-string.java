class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length() > s2.length())
            return false;
        
        HashMap<Character, Integer> M = new HashMap<>();
        for(int i=0; i<s1.length(); i++){
            char c = s1.charAt(i);
            var cur_val = M.computeIfAbsent(c, k -> 0);
            M.put(c, cur_val+1);
        }
        int cnt = M.size();
        
        for(int i=0; i<s1.length(); i++){
            char cur_char = s2.charAt(i);
            if(M.containsKey(cur_char)){
                int prev_cnt = M.put(cur_char, M.get(cur_char)-1);
                if(prev_cnt == 1)
                    cnt--;
            }
        }
        
        int l = 1, r = s1.length();
        while(r<s2.length()){
            if(cnt==0)
                return true;
            
            var l_char = s2.charAt(l-1);
            var r_char = s2.charAt(r);
            if(M.containsKey(l_char)){
                int prev_cnt = M.put(l_char, M.get(l_char)+1);
                if(prev_cnt == 0)
                    cnt++;
            }
            if(M.containsKey(r_char)){
                int prev_cnt = M.put(r_char, M.get(r_char)-1);
                if(prev_cnt == 1)
                    cnt--;
            }
            
            l++;
            r++;
        }
        
        return cnt==0;
    }
}