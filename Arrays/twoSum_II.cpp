/*
 * LeetCode Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * * Question Detail: 
 * Given a 1-indexed array of integers 'numbers' that is already sorted in 
 * non-decreasing order, find two numbers such that they add up to a specific 
 * 'target' number. You must return the indices of the two numbers, 
 * index1 and index2, added by one.
 *
 * Approach:
 * Since the array is sorted, we use two pointers: 'i' at the start and 'j' 
 * at the end. We calculate the sum of elements at these pointers. If the 
 * sum is greater than the target, we move the right pointer ('j') leftward 
 * to decrease the sum. If the sum is less than the target, we move the 
 * left pointer ('i') rightward to increase the sum.
 *
 * Difficulty: Medium
 * * Time Complexity: O(n) - In the worst case, each element is visited 
 * at most once as the pointers converge.
 * Space Complexity: O(1) - Constant extra space is used (excluding the 
 * output vector).
 */
# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        int sum;
        vector <int> ans;
        while(i<j){
            sum=numbers[j]+numbers[i];
            if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;
            }
            else {
                // The problem specifically asks for 1-indexed results
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};