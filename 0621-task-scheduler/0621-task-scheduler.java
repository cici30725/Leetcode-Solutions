class Solution {
    public int leastInterval(char[] tasks, int n) {
        HashMap<Character, Integer> HM = new HashMap<>();
        for(char c : tasks){
            var cnt = HM.computeIfAbsent(c, k -> 0);
            HM.put(c, cnt+1);
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(Map.Entry<Character, Integer> entry : HM.entrySet()){
            // System.out.format("%c, %d\n", entry.getKey(), entry.getValue());
            pq.offer(entry.getValue());
        }
        
        Queue<int[]> queue = new LinkedList<>();
        int cur_time = 0;
        while(!pq.isEmpty() || !queue.isEmpty()){
            // System.out.format("Cur time %d\n", cur_time);
            while(!queue.isEmpty() && cur_time-queue.peek()[1]>n){
                var cur = queue.poll();
                pq.offer(cur[0]);
                // System.out.format("Inserting %d\n", cur[0]);
            }
            
            if(!pq.isEmpty()){
                int cur_num = pq.poll();
                // System.out.format("Removeing %d\n", cur_num);
                cur_num--;
                if(cur_num>0){
                    queue.offer(new int[]{cur_num, cur_time});
                }
            }
            
            
            cur_time++;
        }
        return cur_time;
    }
}