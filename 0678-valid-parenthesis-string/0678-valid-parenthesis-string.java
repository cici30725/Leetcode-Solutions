class Solution {
    public boolean checkValidString(String s) {
        int left = 0;
        int right = 0;
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(c=='('){
                left++;
                right++;
            }
            else if(c==')'){
                left = Math.max(left-1, 0);
                right--;
            }
            else{
                left = Math.max(left-1, 0);
                right++;
            }
            
            if(right<0)
                return false;
        }
        
        return left==0;
    }
}