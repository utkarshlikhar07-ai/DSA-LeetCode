/*
 * LeetCode Link: https://leetcode.com/problems/find-peak-element/
 * * Question Detail: 
 * A peak element is an element that is strictly greater than its neighbors. 
 * Given a 0-indexed integer array 'nums', find a peak element, and return its index. 
 * If the array contains multiple peaks, return the index to any of the peaks. 
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Approach:
 * This solution employs a shrinking window strategy. By comparing the element 
 * at 'mid' with the element at 'end', the pointers 'start' and 'end' 
 * gradually close in on a local maximum. While it functions similarly to a 
 * search, it specifically looks for the point where the increasing trend 
 * stops.
 *
 * Difficulty: Medium
 * * Time Complexity: O(n) - In this specific implementation, the pointers 
 * move linearly towards each other (one step per iteration).
 * Space Complexity: O(1) - Constant space used for index pointers.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(nums[end]<nums[mid]) end--;
            else start++;
        }
        return end;
    }
};