class Solution {
public:
    int numFac(int n, int f){
        int sol = 0;
        while(n>0 && n%f==0){
            sol++;
            n/=f; 
        }
        return sol;
    }
    int trailingZeroes(int n) {
        int two = 0, five = 0;
        for(int i=0; i<=n; i++){
            two += numFac(i, 2);
            five += numFac(i, 5);
        }
        return min(two, five);
    }
};