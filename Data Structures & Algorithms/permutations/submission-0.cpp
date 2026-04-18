class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    unordered_map<int,bool> hash;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
    void dfs(vector<int>& nums){

        if (temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for (int i = 0; i< nums.size(); i++) {
            if (!hash[nums[i]]){
            hash[nums[i]]=true;
            temp.push_back(nums[i]);
            dfs(nums);
            temp.pop_back();
            hash[nums[i]]=false;
            }
        }
    }
};
