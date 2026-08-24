class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        vector<string> cols(n);
        vector<string> rows(n);
        for(int i=0; i < n; i++) {
            cols[i] = words[i];
        }
        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                if (i < words[j].size())
                    rows[i] += words[j][i];
            }
        }

        for(int i=0; i < n; i++) {
            if (cols[i] != rows[i]) return false;
        }

        for (string c : cols) {
            printf("%s\n", c.c_str());
        } printf("rows\n");
        for (string c : rows) {
            printf("%s\n", c.c_str());
        }
        return true;
    }
};
