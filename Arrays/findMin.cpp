/*
 * LeetCode Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * * Question Detail: 
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n 
 * times. For example, the array nums = [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2].
 * Given the sorted rotated array 'nums' of unique elements, return the minimum 
 * element of this array.
 *
 * Approach:
 * The solution implements Binary Search. By comparing the 'mid' element with the 
 * rightmost element 'j', we can determine which half of the array contains the 
 * minimum. If 'nums[mid] > nums[j]', the minimum must be in the right half 
 * (excluding mid). Otherwise, it is in the left half (including mid).
 *
 * Difficulty: Medium
 * * Time Complexity: O(log n) - The search space is halved in every iteration.
 * Space Complexity: O(1) - The search is performed in-place with constant overhead.
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int j=nums.size()-1;
        while(start<j){
            int mid = start+(j-start)/2;
            if(nums[mid]>nums[j]) start=mid+1;
            else j=mid;
        }
        return nums[start];
    }
};