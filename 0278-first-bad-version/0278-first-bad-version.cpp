// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int l = 0;
        unsigned int r = static_cast<unsigned int>(n)+1;
        while(r-l>1){
            unsigned int m = l + (r-l)/2;
            if(isBadVersion(m))
                r = m;
            else
                l = m;
        }
        
        return r;
    }
};