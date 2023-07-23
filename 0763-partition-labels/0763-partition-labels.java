class Solution {
    public List<Integer> partitionLabels(String s) {
        var M = new HashMap<Character, Integer>();
        for(int i=0; i<s.length(); i++)
            M.put(s.charAt(i), i);
        
        var sol = new ArrayList<Integer>();
        int l = 0;
        while(l<s.length()){
            int r = M.get(s.charAt(l));
            int cur_len = 1;
            while(l<r){
                r = Math.max(r, M.get(s.charAt(l)));
                l++;
                cur_len++;
            }
            l++;
            sol.add(cur_len);
        }
        return sol;
    }
}