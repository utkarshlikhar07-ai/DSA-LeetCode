/*
 * LeetCode Link: https://leetcode.com/problems/sort-colors/
 * * Question Detail: 
 * Given an array 'nums' with n objects colored red, white, or blue, sort 
 * them in-place so that objects of the same color are adjacent, with 
 * the colors in the order red (0), white (1), and blue (2).
 *
 * Approach:
 * This implementation uses the C++ Standard Library's 'std::sort' function. 
 * Under the hood, this is typically an Introsort (a hybrid of Quicksort, 
 * Heapsort, and Insertion Sort). While it solves the problem, it does 
 * not take advantage of the fact that there are only three unique 
 * values (0, 1, 2).
 *
 * Difficulty: Medium
 * * Time Complexity: O(n log n) - This is the standard complexity for 
 * comparison-based sorting algorithms like 'std::sort'.
 * Space Complexity: O(log n) - Stack space used by the recursive 
 * calls of the sorting algorithm.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};