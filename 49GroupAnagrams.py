class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dict = {}
        for currstr in strs:
            sorted_str = ''.join(sorted(currstr))
            if sorted_str in dict:
                dict[sorted_str].append(currstr)
            else:
                dict[sorted_str] = [currstr]
        return list(dict.values())

if __name__ == "__main__":
    tester = Solution()
    test_cases = [
        (["eat","tea","tan","ate","nat","bat"]),
        (["a"]),
        ([])
    ]
    for case in test_cases:
        result = tester.groupAnagrams(case)
        print(f"groupAnagrams({case}) = {result}")