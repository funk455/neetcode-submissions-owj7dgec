class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjlist = [[] for _ in range(n)]
        for i,j in edges:
            adjlist[i].append(j)
            adjlist[j].append(i)
        visited = set()
        cnt = 0
        def dfs(cur,pre):
            if cur in visited:
                return;
            visited.add(cur)
            for nextp in adjlist[cur]:
                if nextp == pre:
                    continue
                dfs(nextp,cur)
        for i in range(n):
            if i not in visited:
                dfs(i,-1)
                cnt+=1;
        return cnt