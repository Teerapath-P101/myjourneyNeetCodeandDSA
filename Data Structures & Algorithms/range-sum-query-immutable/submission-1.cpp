class NumArray {
private:
    vector<int>prefixSum;
public:
    NumArray(vector<int>& nums) {
        int currSum = 0;
        for (int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            prefixSum.push_back(currSum);
        }
    }
    
    int sumRange(int left, int right) {
        return (!left) ? prefixSum[right] : prefixSum[right] - prefixSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */