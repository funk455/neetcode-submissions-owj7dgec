class Solution {
public:
    unordered_map<char,int> col;
    vector<int> partitionLabels(string s) {
        for (int i = 0; i < s.size(); i++){
            col[s[i]]=i;
        }
        vector<int> res;
        int start = 0;
        int farthest = 0;
        for (int i = 0; i < s.size(); i++) {
            farthest = max(farthest,col[s[i]]);
            if (i == farthest) {
                res.push_back(i-start+1);
                start = i+1;
            }
        }
        return res;
    }
};
