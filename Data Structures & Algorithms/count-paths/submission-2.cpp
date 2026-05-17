// Bottom Up
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev_row(n);
        for (int _ = m-1; _ >= 0; _--) {
            vector<int> curr_row(n, 1);
            for (int r = n-2; r >= 0; r--) {
                curr_row[r] = prev_row[r] + curr_row[r+1];
            }
            prev_row = curr_row;
        }
        return prev_row[0];
    }
};