from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [] 
        hash_map = {}
        for i, j in enumerate(nums):
            key = target - j
            if key in hash_map.keys:
                return [hash_map[key], i]
            hash_map[j] = i 
        return [] 

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return []
        for i, j in enumerate(nums):
            for k in range(i + 1, len(nums)):
                if target == nums[k] + j:
                    return target
        
        return []
