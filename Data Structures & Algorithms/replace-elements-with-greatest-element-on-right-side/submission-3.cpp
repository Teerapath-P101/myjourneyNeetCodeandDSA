// Start from the right to left to reduce repetitive work
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        int rightMax = -1;
        int curr;
        for (int i = size-1; i >= 0; i--) {
            curr = arr[i];
            arr[i] = rightMax;
            if (rightMax < curr) rightMax = curr;
        }
        return arr;
    }
};