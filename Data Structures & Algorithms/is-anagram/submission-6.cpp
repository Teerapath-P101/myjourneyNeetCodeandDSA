class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> ss;
        for (int i = 0; i < s.size(); i++) {
            ss[s[i]]++;
        }
        for (char c : t) {
            //printf("%c : %d\n", c, ss[c]);
            if (ss[c] == 0) return false;
            ss[c]--;
        }
        return true;
    }
};
