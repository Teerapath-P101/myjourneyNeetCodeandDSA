class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX, sum = 0, l = 0;
        for (int r=0; r < nums.size(); r++) {
            sum += nums[r];
            while(sum >= target) {
                minLength = min(minLength, r - l + 1);
                sum -= nums[l++];
            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};