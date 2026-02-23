# Problem: Longest Substring Without Repeating Characters
# Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
# Difficulty: Medium
#
# Approach:
# 1. Maintain a temporary string `temp` that stores the current substring
#    without repeating characters.
# 2. Traverse the input string character by character.
# 3. If the character is not in `temp`, append it.
# 4. If it is already present:
#       - Store the length of current `temp`
#       - Remove characters from `temp` up to and including
#         the first occurrence of the repeated character
#       - Append the current character
# 5. Keep track of all substring lengths in list `n`
#    and return the maximum.
#
# Time Complexity: O(n^2)
#   Because checking "in temp" and slicing operations
#   take linear time.
#
# Space Complexity: O(n)
#   For storing substring and length list.
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        temp = ""
        n = []
        for i in range(0, len(s)):
            if s[i] not in temp:
                temp = temp + s[i]
            else:
                n.append(len(temp))
                temp = temp[temp.index(s[i]) + 1:]
                temp = temp + s[i]
        n.append(len(temp))
        return max(n)
