class Solution {
public:
    int change(int amount, vector<int>& coins) {
         sort(coins.begin(), coins.end());
        vector<vector<int>> mem(coins.size()+1,vector<int>(amount+1,-1));
        return dfs(mem,0,amount,coins);
    }
    int dfs( vector<vector<int>> &mem,int i, int amount,vector<int>& coins) {
        if (amount<0 || i >=coins.size()) return 0;
        if (amount==0) return 1;
        if (mem[i][amount] != -1) return mem[i][amount];
        int exclude = dfs(mem,i+1,amount,coins);
        int include = 0;
        if (amount>=coins[i]){
            include=dfs(mem,i,amount-coins[i],coins);
        }
        return  mem[i][amount] = exclude+include;
    }
};
