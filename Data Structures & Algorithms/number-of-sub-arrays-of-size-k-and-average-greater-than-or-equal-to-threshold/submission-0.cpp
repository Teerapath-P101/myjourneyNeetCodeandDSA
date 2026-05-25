class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int total = 0;
        int l = 0;
        int res = 0;
        for (int r = 0; r < arr.size(); r++) {
            total += arr[r];
            if ((r - l + 1) == k) {
                res += (total/k >= threshold) ? 1 : 0;
                total -= arr[l];
                l++;
            }
        }
        return res;
    }
};