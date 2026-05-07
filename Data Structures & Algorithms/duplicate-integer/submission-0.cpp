class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> nums_inHash;
        for (int i : nums) {
            bool check = nums_inHash.contains(i);
            if(check) nums_inHash[i] += 1;
            nums_inHash.insert({i, 0});
            if (check && nums_inHash[i] == 1) return true;
        }
        return false;
    }
};