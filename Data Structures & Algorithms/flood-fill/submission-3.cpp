// BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        if (start == color) return image;
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> queue_;
        queue_.emplace(sr, sc);
        image[sr][sc] = color;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!queue_.empty()) {
            auto [r, c] = queue_.front(); queue_.pop();
            for (auto &dir : directions) {
                int nextr = r + dir[0], nextc = c + dir[1];
                if (nextr >= 0 && nextc >= 0 && nextr < m && nextc < n &&
                    image[nextr][nextc] == start)
                {
                    image[nextr][nextc] = color;
                    queue_.emplace(nextr, nextc);
                }
            }
        }
        return image;
    }
};