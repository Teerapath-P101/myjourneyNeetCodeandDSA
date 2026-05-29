// Using two pointer and
// we already know that the Array is ascending order sorted(btw technically not)
// so using two pointer one is checking that the prevoius position is the same ascurrent position
// one is to update nums position and return as k
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        for (int r = 1; r < nums.size(); r++) {
            if (nums[r - 1] != nums[r]) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};