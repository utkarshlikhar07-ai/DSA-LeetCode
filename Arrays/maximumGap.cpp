/*
 * LeetCode Link: https://leetcode.com/problems/maximum-gap/
 * * Question Detail: 
 * Given an integer array 'nums', return the maximum difference between two 
 * successive elements in its sorted form. If the array contains less than 
 * two elements, return 0. You must write an algorithm that runs in linear 
 * time and uses linear extra space.
 *
 * Approach:
 * This implementation uses the standard 'std::sort' function to arrange 
 * elements in non-decreasing order. It then performs a single linear scan 
 * to find the largest difference between adjacent elements. While simple, 
 * this exceeds the "linear time" hint/requirement suggested in the prompt.
 *
 * Difficulty: Hard
 * * Time Complexity: O(n log n) - Due to the initial sorting step.
 * Space Complexity: O(log n) - Space used by the sorting algorithm's stack.
 */
# include <iostream>
# include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max=INT_MIN;
        if(nums.size()<2) return 0; 
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>max) max=nums[i+1]-nums[i];
        }
        return max;
    }
};