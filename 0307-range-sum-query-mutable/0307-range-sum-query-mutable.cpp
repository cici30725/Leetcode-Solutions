class NumArray {
    vector<int> sum;
    int size;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        size = 1;
        while(size < n) size *= 2;
        sum = vector<int>(2*size-1, 0);
        build(nums);
    }
    
    void build(vector<int>& nums) {
        build(nums, 0, 0, size);
    }
    
    void build(vector<int>& nums, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < nums.size()){
                sum[x] = nums[lx];
            }
            return;
        }
        
        int mx = (lx+rx)/2;
        build(nums, 2*x+1, lx, mx);
        build(nums, 2*x+2, mx, rx);
        sum[x] = sum[2*x+1] + sum[2*x+2];
    }
    
    void update(int index, int val, int x, int lx, int rx){
        if(rx-lx==1){
            sum[x] = val;
            return;
        }
        
        int mx = (lx+rx)/2;
        if(index < mx)
            update(index, val, 2*x+1, lx, mx);
        else
            update(index, val, 2*x+2, mx, rx);
        
        sum[x] = sum[2*x + 1] + sum[2*x+2];
    }
    
    void update(int index, int val) {
        update(index, val, 0, 0, size);
    }
    
    int sumRange(int left, int right, int x, int lx, int rx){
        if(right <= lx || left >= rx)
            return 0;
        
        if(left<=lx && right>=rx)
            return sum[x];
        
        int mx = (lx+rx)/2;
        int sum_l = sumRange(left, right, 2*x+1, lx, mx);
        int sum_r = sumRange(left, right, 2*x+2, mx, rx);
        return sum_l + sum_r;
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right+1, 0, 0, size);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */