class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash.insert({nums[i], i});
            if (hash.contains(target - nums[i]) && i != hash[target - nums[i]]) return {hash[target - nums[i]], i};
        }
    }
};
