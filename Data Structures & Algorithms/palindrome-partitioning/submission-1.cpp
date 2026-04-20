class Solution {
public:
    vector<vector<string>> res;
    bool ispalindrome(string s,int l,int r){
        while(l < r){
            if (s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        dfs(0,s,temp);
        return res;
    }
    void dfs(int i,string s,vector<string> temp) {
        if (i>=s.size()){
            res.push_back(temp);
            return;
        }
        //combinatioptional
        for (int j = i;j < s.size(); j++){
            if (ispalindrome(s,i,j)){
                temp.push_back(s.substr(i, j-i+1));
                dfs(j+1,s,temp);
                temp.pop_back();
            }
        }
    }
};
