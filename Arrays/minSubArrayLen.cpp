/*
 * LeetCode Link: https://leetcode.com/problems/minimum-size-subarray-sum/
 * * Question Detail: 
 * Given an array of positive integers 'nums' and a positive integer 'target', 
 * find the minimal length of a subarray whose sum is greater than or equal 
 * to 'target'. If there is no such subarray, return 0 instead.
 *
 * Approach:
 * The solution uses a "Sliding Window" (two-pointer) strategy. The right 
 * pointer 'j' expands the window by adding elements to 'sum'. Once 'sum' 
 * reaches or exceeds the target, the left pointer 'i' contracts the window 
 * to find the smallest possible length while still maintaining the sum 
 * condition. An initial sum check is performed to return 0 if the total 
 * sum of the array is less than the target.
 *
 * Difficulty: Medium
 * * Time Complexity: O(n) - Although there is a nested while loop, 
 * each element is visited at most twice (once by 'j' and once by 'i').
 * Space Complexity: O(1) - The solution uses a constant amount of 
 * extra space for variables.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int sum=0;
        int ans=INT_MAX;
        int check=0;
        for(int h=0;h<nums.size();h+=1){
            check+=nums[h];
        }
        if(check<target) return 0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return ans;
    }
};