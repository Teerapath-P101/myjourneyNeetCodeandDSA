class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> ss;
        unordered_map<char, int> tt;
        for (int i = 0; i < s.size(); i++) {
            if (ss.contains(s[i])) ss[s[i]] += 1;
            ss.insert({s[i], 1});
            if (tt.contains(t[i])) tt[t[i]] += 1;
            tt.insert({t[i], 1});
        }
        for (char c : s) {
            if (ss[c] != tt[c]) return false;
        }
        return true;
    }
};
