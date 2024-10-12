class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        dic = { "2": "abc", "3": "def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}

        res = []
        if len(digits) == 0:
            return res
        self.dfs(digits,0,dic,'',res)
        return res

    def dfs(self,nums,index,dic,path,res):
        if index >= len(nums):
            res.append(path)
            return
        for x in dic[nums[index]]:
            self.dfs(nums,index+1,dic,path+x,res)

if __name__ == "__main__":
    sol = Solution()
    print(sol.letterCombinations("23"))
    print(sol.letterCombinations("37"))