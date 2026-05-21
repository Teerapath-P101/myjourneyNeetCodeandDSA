// Brute Force

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        for (int i=0; i< size - 1; i++) {
            int maxRight = -1;
            for (int j=i+1; j<size; j++) {
                if (maxRight < arr[j]) maxRight = arr[j];
            }
            arr[i] = maxRight;
        }
        arr[size - 1] = -1;
        return arr;
    }
};