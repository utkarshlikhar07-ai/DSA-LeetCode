/*
 * LeetCode Link: https://leetcode.com/problems/jump-game/
 * * Question Detail: 
 * You are given an integer array 'nums'. You are initially positioned at the 
 * array's first index, and each element in the array represents your maximum 
 * jump length at that position. Return true if you can reach the last index, 
 * or false otherwise.
 *
 * Approach:
 * This solution uses a greedy local search. At each position 'i', it looks 
 * ahead at all possible jumps (from 1 to nums[i]) and identifies the 'bestJump'. 
 * The 'bestJump' is defined as the index that provides the maximum potential 
 * reach (current index + jump distance + value at that new index). The 
 * algorithm then moves directly to that best position.
 *
 * Difficulty: Medium
 * * Time Complexity: O(n) - Although there is a nested loop, the pointer 'i' 
 * effectively moves forward through the array, visiting each element once.
 * Space Complexity: O(1) - The solution uses a constant amount of extra 
 * space for tracking indices and reaches.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        while (i<nums.size()){
            if (i==nums.size()-1) return true;
            if (nums[i]==0) return false;
            int bestJump=i;
            int maxReach=0;

            for (int j=1; j <=nums[i]&& i+j< nums.size();j++) {
                if (i+j+nums[i+j] > maxReach) {
                    maxReach= i +j+nums[i+ j];
                    bestJump=i +j;
                }
                // Optimization: If a jump can reach the end, take it immediately
                if (i+j >= nums.size()-1) return true;
            }
            i=bestJump;
        }
        return false;
    }
};