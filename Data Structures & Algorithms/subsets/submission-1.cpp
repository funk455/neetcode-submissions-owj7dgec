class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(nums,0,temp);
        return res;
    }
    void dfs(vector<int> & nums,int index,vector<int> &temp){
        if ( index>=nums.size()){
            res.push_back(temp);
            return;
        }
        //decision1alignas
        temp.push_back(nums[index]);
        dfs(nums,index+1,temp);
        //decision2alignas
        temp.pop_back();
        dfs(nums,index+1,temp);
    }
};
