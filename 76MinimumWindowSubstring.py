class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        charcount = [0]*128
        minlength = len(s) + 1
        minstart = 0
        start = 0
        count = len(t)
        for char in t:
            charcount[ord(char)] += 1
        for end in range(len(s)):
            if charcount[ord(s[end])] > 0:
                count -= 1
            charcount[ord(s[end])] -= 1
            while count == 0:
                if end - start + 1 < minlength:
                    minlength = end-start+1
                    minstart = start
                if charcount[ord(s[start])] == 0:
                    count += 1
                charcount[ord(s[start])] += 1
                start += 1
        return s[minstart:minstart+minlength] if minlength < len(s) + 1 else ""

if __name__ == "__main__":
    tester = Solution()
    test_cases = [
        ("ADOBECODEBANC","ABC","BANC"),
        ("a","a","a"),
        ("a","aa",""),
        ("aabdec","abc","abdec"),
        ("abcdef","xyz",""),
        ("a","ab","")
    ]
    for s,t,expected in test_cases:
        result = tester.minWindow(s,t)
        print(f"minWindow({s}, {t}) = {result}, expected = {expected}")
        assert result == expected, f"test failed"
