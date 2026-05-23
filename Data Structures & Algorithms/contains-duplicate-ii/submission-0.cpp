class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (!k) return false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j <= (int)min((size_t)(i + k), nums.size() - 1); j++) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};