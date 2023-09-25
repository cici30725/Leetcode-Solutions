class Solution {
public:
    int countOdds(int low, int high) {
        int a = low/2;
        int b = high/2;
        int num_even = b-a + (low%2==0 ? 1 : 0);
        return (high-low+1) - num_even;
    }
};