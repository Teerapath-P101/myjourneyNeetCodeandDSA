// Dynamic programming
// (it's consider to be Bottom-Up too) Time complexity: O(n), Space complexity: O(1)
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 2) return n;
//         int one = 1, two = 2;
//         for (int i=3; i <= n; i++) {
//             int tmp = one + two;
//             one = two;
//             two = tmp;
//         }
//         return two;
//     }
// };

class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1; // one is current step two is the step before that
                              // `one` is ALWAYS one step ahead of `two`!
        for (int i=0; i < n-1; i++) {
            int tmp = one;
            one += two; // the current step to be added with the two
            two = tmp; // (the previos step which old the one)
        }
        return one;
    } //The Window Sliding Visualization
};