class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char,int> ma;
        int l = 0;
        int maxc = 0;
        for ( int r = 0; r <s.size(); r++ ){
            ma[s[r]]++;
            maxc = max(maxc,ma[s[r]]);
            while (r-l+1-maxc > k) {
                ma[s[l]]--;
                l++;
            }
            res = max(r-l+1,res);
        }
        return res;
    }
};
