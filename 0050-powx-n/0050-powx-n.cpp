class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)
            return 0;
        bool flag  =false;
        if(n<0)
            flag =true;
        
        double res = 1;
        while(n!=0){
            if(n%2!=0)
                res *= x;
            x *= x;
            n /= 2;
        }
        
        if(flag)
            return 1/res;
        else
            return res;
    }
};