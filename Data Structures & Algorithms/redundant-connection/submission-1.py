class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        size = len(edges)
        rank=[1]*(size+1)
        par=[i for i in range(size+1)]
        def find(n):
            p = par[n]
            while p!=par[p]:
                par[p] = par[par[p]]
                p = par[p]
            return p
        def union(u,v):
            pu = find(u)
            pv = find(v)
            if pu==pv:
                return False
            elif rank[pu] > rank[pv]:
                par[pv] = pu
                rank[pu] += rank[pv]
            else: 
                par[pu] = pv
                rank[pv] += rank[pu]
            return True
        for u,v in edges:
            if not union(u,v):
                return [u,v]
        return []