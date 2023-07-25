class Solution {
    boolean dfs(int idx, ArrayList<ArrayList<Integer>> adjList, int[] visit, Stack<Integer> S){
        visit[idx] = 1;
        
        boolean flag = true;
        for(int to : adjList.get(idx)){
            if(visit[to]==0){
                if(!dfs(to, adjList, visit, S))
                    return false;
            }
            else if(visit[to]==1)
                return false;
        }
        
        S.push(idx);
        visit[idx] = 2;
        return flag;
    }
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();
        int[] visit = new int[numCourses];
        for(int i=0; i<numCourses; i++){
            adjList.add(new ArrayList<>());
        }
        
        for(int[] arr : prerequisites){
            adjList.get(arr[1]).add(arr[0]);
        }
        
        var S = new Stack<Integer>();
        for(int i=0; i<numCourses; i++){
            if(visit[i]==0){
                boolean flag = dfs(i, adjList, visit, S);
                if(!flag)
                    return new int[0];
            }
        }
        
        int[] sol = new int[numCourses];
        for(int i=0; i<numCourses; i++)
            sol[i] = S.pop();
        return sol;
    }
}