class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        l = 0
        r = len(matrix[0])
        top,but = 0,len(matrix)
        while l < r and top < but:
            for i in range(l,r):
                res.append(matrix[top][i])
            top+=1
            for i in range(top,but):
                res.append(matrix[i][r-1])
            r-=1
            if not (l < r and top < but):
                break            
            for i in range(r-1,l-1,-1):
                res.append(matrix[but-1][i])
            but-=1
            for i in range(but-1,top-1,-1):
                res.append(matrix[i][l])
            l+=1
        return res
            