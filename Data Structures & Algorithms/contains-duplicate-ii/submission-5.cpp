// Better O(n)
// using HashSet (Sliding Window Fixed Size)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int l = 0;
        for(int r=0; r<nums.size(); r++) {
            if (r - l > k) {
                window.erase(nums[l]); // remove the oldest value in window
                l++;
            }
            if (window.count(nums[r])) return true;
            window.insert(nums[r]);
        }
        return false;
    }
};  