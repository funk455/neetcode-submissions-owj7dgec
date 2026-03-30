class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        unordered_map<char,int> cntt;
        int have = 0,need = 0;
        for ( auto & c : t){
            cntt[c]++;
        }
        need = cntt.size();
        pair<int,int> res = {-1,-1};
        int l = 0,min = INT_MAX;
        unordered_map<char,int> cnto;
        for (int r = 0; r < s.size(); r++) {
            cnto[s[r]]++;
            if ( cntt.count(s[r]) > 0 && cnto[s[r]] == cntt[s[r]] )
                have++;
            while (have == need) {
                if ( r-l+1 < min) {
                    min = r-l+1;
                    res = {l,r};
                }
                cnto[s[l]]--;
                if ( cntt.count(s[l]) && cnto[s[l]] < cntt[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return min == INT_MAX?"":s.substr(res.first,min);
    }
};
