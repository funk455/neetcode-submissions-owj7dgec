class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        l ,r = 0, len(matrix)-1
        while l < r:
            # 每层需要旋转的次数=边长-1
            for i in range(r-l):
                top,but = l,r
                topleft = matrix[top][l+i]
                matrix[top][l+i] = matrix[but-i][l]
                matrix[but-i][l] = matrix[but][r-i]
                matrix[but][r-i] = matrix[top+i][r]
                matrix[top+i][r] = topleft
            r-=1
            l+=1
                