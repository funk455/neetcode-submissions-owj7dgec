class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::map<char,int> shash,thash;
        for (int i = 0; i < s.length(); i++) {
            shash[s[i]]++;
            thash[t[i]]++;
        }
        return shash == thash;
    }
};
