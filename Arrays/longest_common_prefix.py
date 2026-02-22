# Problem: Longest Common Prefix
# Link: https://leetcode.com/problems/longest-common-prefix/
# Difficulty: Easy
#
# Approach:
# 1. If the list is empty, return an empty string.
# 2. Take the first string as reference.
# 3. Compare each character of the first string with the
#    character at the same index in every other string.
# 4. If any mismatch occurs, return the prefix built so far.
# 5. If all characters match, keep adding to prefix.
#
# Time Complexity: O(n * m)
#   n = number of strings
#   m = length of the smallest string
#
# Space Complexity: O(1)
#   (Only using a few extra variables)

from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        prefix = ""
        for i in range(len(strs[0])):
            char = strs[0][i]
            for string in strs:
                if i >= len(string) or string[i] != char:
                    return prefix
            prefix += char
        return prefix
