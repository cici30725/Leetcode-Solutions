class Solution {
    int comp(int[] a, int[] b){
        return (a[0]*a[0] + a[1]*a[1]) - (b[0]*b[0] + b[1]*b[1]);
    }
    
    void quickSelect(int[][] points, int l, int r, int k){
        int[] pivot = points[r];
        int ll = l-1, cur = l;
        while(cur<r){
            if(comp(points[cur], pivot)<=0){
                ll++;
                var tmp = points[ll];
                points[ll] = points[cur];
                points[cur] = tmp;
            }
            cur++;
        }
        ll++;
        int cnt = ll-l+1;
        
        var tmp = points[ll];
        points[ll] = points[r];
        points[r] = tmp;
        
        if(cnt == k)
            return;
        else if(cnt<k)
            quickSelect(points, ll+1, r, k-cnt);
        else
            quickSelect(points, l, ll-1, k);
    }
    public int[][] kClosest(int[][] points, int k) {
        quickSelect(points, 0, points.length-1, k);
        return Arrays.copyOfRange(points, 0, k);
    }
}