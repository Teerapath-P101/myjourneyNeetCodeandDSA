// using Memoization
// Top-Down
class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {
        if (n <= 1) return 1;
        if (cache.count(n)) return cache[n];
        return cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
