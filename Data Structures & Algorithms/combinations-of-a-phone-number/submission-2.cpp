class Solution {
public:
    unordered_map<char,string> hash;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        backtracing(0,"",digits);
        return res;
    }
    void backtracing(int i, string temp,string digits){
        if (temp.size() == digits.size()) {
            res.push_back(temp);
            return;
        }
        string chars = hash[digits[i]];
        for (char c : chars) {
            backtracing(i+1,temp + c,digits);
        }
    }
};
