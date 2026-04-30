class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // passing nums2 elements to nums1 placeholders
        // for (int i = m; i < (m+n); i++) {
        //     nums1[i] = nums2[i-m];
        // }
        // // merge
        // // slice nums1 in to left right array
        // vector<int> left(nums1.begin() + 0, nums1.begin() + m);
        // vector<int> right(nums1.begin() + m, nums1.begin() + m+n);
        vector<int> left = nums1;
        vector<int> right = nums2;
        int l = 0, r = 0, k = 0; //Three pointer to compare and place
        while (r < n && l < m) {
            if (left[l] > right[r]) {
                nums1[k++] = right[r++];
            } else {
                nums1[k++] = left[l++];
            }
        }
        while(r < n) {
            nums1[k++] = right[r++];
        }
        while(l < m) {
            nums1[k++] = left[l++];
        }
    }
};