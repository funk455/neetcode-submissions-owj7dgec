class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int maxl = 0;
        int cur = 0;
        int res = 0;
        unordered_map<char, int> seen;
        int start = 0;
        while ( cur < s.size()) {
            if (seen.find(s[cur]) != seen.end() && seen[s[cur]] >= start){
                start = seen[s[cur]] + 1;
            }
            seen[s[cur]] = cur;
            maxl = cur - start + 1;
            res = max(maxl,res);
            cur++;
        }
        return res;
    }
};