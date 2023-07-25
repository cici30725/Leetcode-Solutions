class Solution {
    void dfs(int[] candidates, int idx, ArrayList<Integer> cur, int target, List<List<Integer>> sol){
        if(idx == candidates.length){
            if(target==0)
                sol.add(new ArrayList<Integer>(cur));
            return;
        }
        if(candidates[idx]<=target){
            cur.add(candidates[idx]);
            dfs(candidates, idx, cur, target-candidates[idx], sol);
            cur.remove(cur.size()-1);
        }
        dfs(candidates, idx+1, cur, target, sol);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> sol = new ArrayList<>();
        dfs(candidates, 0, new ArrayList<Integer>(), target, sol);
        return sol;
    }
}