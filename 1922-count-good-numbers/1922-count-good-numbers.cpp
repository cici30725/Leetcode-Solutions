class Solution {
public:
    using ll = long long;
    
    ll modulo = 1e9 + 7;
    ll modPow(ll base, ll p){
        ll res = 1;
        while(p>0){
            if(p & 1)
                res = (res * base) % modulo;
            p>>=1;
            base = (base*base)%modulo;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        if(n%2==0)
            return (modPow(5, n/2)*modPow(4, n/2)) % modulo;
        else
            return (modPow(5, n/2+1)*modPow(4, n/2))%modulo;
    }
};