class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length % groupSize !=0)
            return false;
        
        var M = new HashMap<Integer, Integer>();
        var S = new TreeSet<Integer>();
        
        for(int i : hand){
            int cur_val = 0;
            if(M.containsKey(i))
                cur_val = M.get(i);
            if(cur_val == 0)
                S.add(i);
            M.put(i, cur_val+1);
        }
        
        while(!S.isEmpty()){
            int cur_num = S.pollFirst();
            int cur_cnt = M.get(cur_num);
            if(cur_cnt==0)
                continue;
            for(int i = cur_num+1; i<cur_num+groupSize; i++){
                if(!M.containsKey(i))
                    return false;
                int next_cnt = M.get(i);
                if(next_cnt < cur_cnt)
                    return false;
                else
                    M.put(i, next_cnt - cur_cnt);
            }
        }
        return true;
    }
}