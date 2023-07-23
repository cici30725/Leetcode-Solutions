class Solution {
    public int findDuplicate(int[] nums) {
        var H = new HashMap<Integer, Integer>();
        for(int i : nums){
            H.put(i, H.getOrDefault(i, 0) + 1);
            if(H.get(i)>1)
                return i;
        }
        return -1;
    }
}