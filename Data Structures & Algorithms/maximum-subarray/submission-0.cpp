class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int Max = INT_MIN; //or nums[0]
    for (int i=0; i<nums.size(); i++) {
      int currSum = 0;
      for (int j=i; j<nums.size(); j++) {
        currSum += nums[j];
        Max = max(Max, currSum);
      }
    }
    return Max;
  }
};
