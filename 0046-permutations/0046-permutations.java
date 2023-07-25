class Solution {
    void dfs(int[] nums, List<List<Integer>> sol, ArrayList<Integer> cur){
        if(cur.size() == nums.length){
            sol.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for(int i : nums){
            if(cur.contains(i))
                continue;
            cur.add(i);
            dfs(nums, sol, cur);
            cur.remove(cur.size()-1);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> sol = new ArrayList<>();
        dfs(nums, sol, new ArrayList<Integer>());
        return sol;
    }
}