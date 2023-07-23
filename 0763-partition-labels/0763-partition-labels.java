class Solution {
    public List<Integer> partitionLabels(String s) {
        var M = new HashMap<Character, Integer>();
        for(int i=0; i<s.length(); i++)
            M.put(s.charAt(i), i);
        
        var sol = new ArrayList<Integer>();
        int size = 0, end = 0;
        for(int i=0; i<s.length(); i++){
            end = Math.max(end, M.get(s.charAt(i)));
            size++;
            
            if(i == end){
                sol.add(size);
                size = 0;
            }
        }
        return sol;
    }
}