class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> S = new HashSet<>();
        while(true){
            if(n==1)
                return true;
            if(S.contains(n))
                break;
            S.add(n);
            
            int next = 0;
            while(n>0){
                next += (n%10)*(n%10);
                n/=10;
            }
            n = next;
        }
        return false;
    }
}