// Dynamic programming
// (it's consider to be Bottom-Up too) T
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int one = 1, two = 2;
        for (int i=3; i <= n; i++) {
            int tmp = one + two;
            one = two;
            two = tmp;
        }
        return two;
    }
};
