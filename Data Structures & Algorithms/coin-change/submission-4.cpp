//res是局部的，是当前子问题层的res，返回给父层子问题的最优解
//res本质上是当前这个 amount，我试了所有 coin 之后得到的最优解
//局部（子问题）的最优解就是总体的最优解
class Solution {
public:
    unordered_map<int,int> mem;
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (mem.count(amount)) return mem[amount];
        int res = INT_MAX;
        for (auto & coin : coins) {
            if (amount - coin>=0) {
                int result = dfs(coins,amount-coin);
                if (result!=INT_MAX)
                    res = min(result+1,res);
            }
        }
        mem[amount] = res;
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins,amount);
        return res == INT_MAX? -1:res;
    }

};
