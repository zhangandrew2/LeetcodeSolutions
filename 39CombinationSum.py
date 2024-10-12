class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        dp = [[] for _ in range(target+1)]
        dp[0].append([])

        for i in range(1,target+1):
            for candidate in candidates:
                if candidate <= i:
                    for combos in dp[i-candidate]:
                        temp = combos + [candidate]
                        temp.sort()
                        if temp not in dp[i]:
                            dp[i].append(temp)
        return dp[target]

if __name__ == "__main__":
    # Example usage:
    sol = Solution()
    print(sol.combinationSum([2, 3, 6, 7], 7))