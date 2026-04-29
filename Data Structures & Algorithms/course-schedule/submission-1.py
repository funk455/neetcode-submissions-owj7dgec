class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        premap = {i:[] for i in range(numCourses)}
        visited = set()
        for cur,pre in prerequisites:
            premap[cur].append(pre)
        def dfs(cur):
            if cur in visited:
                return False
            if len(premap[cur])==0:
                return True
            visited.add(cur)
            for c in premap[cur]:
                if not dfs(c):
                    return False
            #回到上一层
            premap[cur].clear()
            visited.remove(cur)
            return True
        for c in range(numCourses):
            if not dfs(c):
                return False
        return True