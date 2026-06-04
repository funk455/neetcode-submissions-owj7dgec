class Solution {
private:
    vector<vector<int>> memo;
    
    bool helper(string& s, string& p, int i, int j) {
        // 记忆化查找
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        // 基础情况：p 用完了
        if (j == p.length()) {
            return memo[i][j] = (i == s.length());
        }
        
        // 检查当前字符是否匹配
        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');
        
        // 处理 '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            bool result = helper(s, p, i, j + 2) ||           // 零个匹配
                          (match && helper(s, p, i + 1, j));  // 一个或多个
            return memo[i][j] = result;
        }
        
        // 普通字符或 '.'
        bool result = match && helper(s, p, i + 1, j + 1);
        return memo[i][j] = result;
    }
    
public:
    bool isMatch(string s, string p) {
        memo.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        return helper(s, p, 0, 0);
    }
};