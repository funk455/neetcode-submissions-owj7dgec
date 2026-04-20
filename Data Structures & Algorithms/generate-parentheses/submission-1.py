class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        temp = []
        def dfs(openid,closeid):
            if openid == n and closeid == n:
                res.append("".join(temp))
                return
            if openid < n:
                temp.append('(')
                dfs(openid+1,closeid)
                temp.pop()
            if closeid < openid:
                temp.append(')')
                dfs(openid,closeid+1)
                temp.pop()
        dfs(0,0)
        return res
