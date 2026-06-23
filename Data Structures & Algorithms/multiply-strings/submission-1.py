class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        if len(num1) < len(num2):
            num1,num2 = num2,num1
        res = ""
        zero = 0
        for i in range(len(num2)-1,-1,-1):
            cur = self.mul(num1,num2[i],zero)
            res = self.add(res,cur)
            zero+=1
        return res
    def mul(self,num1,num,zero):
        i,carry = len(num1)-1,0
        num = int(num)
        cur = []
        while i >=0 or carry:
            n = int(num1[i]) if i >=0 else 0
            c = n * num + carry
            cur.append(str(c%10))
            carry = c//10
            i-=1
        return ''.join(cur[::-1]) + '0' * zero
    def add(self,res,cur):
        i ,j,carry = len(res)-1,len(cur)-1,0
        r = []
        while i>=0 or j>=0 or carry>0:
            n1 = int(res[i]) if i>=0 else 0
            n2 = int(cur[j]) if j >=0 else 0
            total = n1 + n2 + carry
            r.append(str(total%10))
            carry = total//10
            i-=1
            j-=1
        return ''.join(r[::-1])
            
        
        
