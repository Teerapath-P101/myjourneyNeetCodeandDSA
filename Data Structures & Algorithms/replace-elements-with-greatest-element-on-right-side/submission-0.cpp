class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        
        // For each element at index i
        for (int i = 0; i < n - 1; i++) {
            int maxRight = INT_MIN;
            // Find the maximum of all elements to the RIGHT
            for (int j = i + 1; j < n; j++) {
                maxRight = max(maxRight, arr[j]);
            }
            arr[i] = maxRight;  // Replace in place
        }
        
        arr[n - 1] = -1;  // Last element is always -1
        
        return arr;
    }
};