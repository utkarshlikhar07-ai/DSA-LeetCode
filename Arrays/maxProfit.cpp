/*
 * LeetCode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * * Question Detail: 
 * You are given an array 'prices' where prices[i] is the price of a given stock 
 * on the ith day. You want to maximize your profit by choosing a single day 
 * to buy one stock and choosing a different day in the future to sell that stock.
 *
 * Approach:
 * The algorithm maintains two variables: 'minPrice', which tracks the lowest 
 * price encountered so far, and 'ans' (max profit), which tracks the maximum 
 * difference between the current price and the 'minPrice'. By iterating through 
 * the list once, we ensure we only consider selling on a day that occurs 
 * after the buying day.
 *
 * Difficulty: Easy
 * * Time Complexity: O(n) - We traverse the prices array exactly once.
 * Space Complexity: O(1) - Only two integer variables are used regardless of input size.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int ans=0;
        for(int price:prices){
            minPrice=min(minPrice, price);
            ans=max(ans, price - minPrice);
        }
        return ans;
    }
};