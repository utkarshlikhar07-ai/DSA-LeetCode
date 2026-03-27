
/*
 * LeetCode Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * * Question Detail: 
 * Given an integer array 'nums' sorted in non-decreasing order, remove some duplicates 
 * in-place such that each unique element appears at most twice. The relative order 
 * of the elements should be kept the same.
 *
 * Approach:
 * This solution uses a single-pass loop with a counter to track consecutive 
 * occurrences of the same value. When the counter exceeds 2, it uses the 
 * vector::erase method to remove the current element from the container. 
 * While intuitive, this approach is less efficient than a two-pointer 
 * method due to the overhead of shifting elements during erasure.
 *
 * Difficulty: Medium
 * * Time Complexity: O(n²) - In the worst case, every erase operation 
 * takes O(n) time, and we iterate through the array once.
 * Space Complexity: O(1) - The removal is done in-place within 
 * the input vector.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count =1; 
        for(int i= 1; i <nums.size();i++) {
            if(nums[i]== nums[i-1]) {
                count++;
            } else {
                count= 1; 
            }
            if(count>2) {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};