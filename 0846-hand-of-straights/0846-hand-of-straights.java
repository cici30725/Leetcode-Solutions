class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length % groupSize !=0)
            return false;
        
        var M = new HashMap<Integer, Integer>();
        for(int i : hand)
            M.put(i, M.getOrDefault(i, 0)+1);
        
        Arrays.sort(hand);
        
        for(int i=0; i<hand.length; i++){
            if(M.get(hand[i])==0)     
                continue;
            for(int j = 0; j<groupSize; j++){
                int next = hand[i] + j;
                if(M.getOrDefault(next, 0) == 0)
                    return false;
                M.put(next, M.get(next)-1);
            }
        }
        return true;
    }
}