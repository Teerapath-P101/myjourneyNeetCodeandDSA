// Reduce repetitive tasks by Dynamic Programming (reuse previously calculated results)

class Solution {
public:
    vector<int> countBits(int n) {
        int offset = 1;
        vector<int> res(n + 1);
        for (int i=1; i<=n; i++) {
            if (offset * 2 == i) {
                offset = i;
            }
            res[i] = 1 + res[i - offset];
        }
        return res;
    }
};
