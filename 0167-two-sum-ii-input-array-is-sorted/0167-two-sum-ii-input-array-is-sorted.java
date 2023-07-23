class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0, r = numbers.length-1;
        while(true){
            int val = numbers[l] + numbers[r];
            if(val==target)
                return new int[]{l+1, r+1};
            else if(val>target)
                r--;
            else
                l++;
        }
    }
}