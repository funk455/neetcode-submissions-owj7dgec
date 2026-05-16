class Solution {
public:
    int res = 0;
    int countSubstrings(string s) {
        for (int i = 0; i < s.size();i ++) {
            int l =i,r=i;
            while (l >=0 && r<s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
             l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() &&
                   s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }
        return res;
    }
};
