from typing import List
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums)-1
        while start <= end:
            mid = (start+end)//2
            if target < nums[mid]:
                end = mid -1
            elif target > nums[mid]:
                start = mid +1
            else:
                return mid
        return start

if __name__ == "__main__":
    
    tester = Solution()
    # Define test cases
    test_cases = [
        ([1, 3, 5, 6], 5, 2),  # Target 5 is at index 2
        ([1, 3, 5, 6], 2, 1),  # Target 2 should be inserted at index 1
        ([1, 3, 5, 6], 7, 4),  # Target 7 should be inserted at index 4 (end of list)
        ([1, 3, 5, 6], 0, 0),  # Target 0 should be inserted at index 0 (beginning of list)
        ([1], 0, 0),            # Single element list, target 0 should be at index 0
    ]

    # Run through test cases
    for nums, target, expected in test_cases:
        result = tester.searchInsert(nums, target)
        print(f"searchInsert({nums}, {target}) = {result}; Expected = {expected}")
        assert result == expected, f"Test failed for input {nums} and target {target}"