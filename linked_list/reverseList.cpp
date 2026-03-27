/*
 * LeetCode Link: https://leetcode.com/problems/reverse-linked-list/
 * * Question Detail: 
 * Given the head of a singly linked list, reverse the list, and return 
 * the reversed list.
 *
 * Approach:
 * The solution uses a "Three-Pointer" iterative approach ('prev', 'curr', 
 * and 'next'). As we traverse the list, we temporarily store the 'next' 
 * node to avoid losing the rest of the list, then flip the 'curr->next' 
 * pointer to point backward to 'prev'. Finally, we move 'prev' and 'curr' 
 * one step forward.
 *
 * Difficulty: Easy
 * * Time Complexity: O(n) - We visit each node exactly once.
 * Space Complexity: O(1) - The reversal is done in-place using a 
 * constant amount of extra space.
 */

/**
 * Definition for singly-linked list. */
 struct ListNode {
    int val;
    struct ListNode *next;
 };
 
#include <bits/stdc++.h>
using namespace std;
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    while(curr != NULL){
        next = curr->next;   // Save the rest of the list
        curr->next = prev;   // Reverse the current link
        prev = curr;         // Move prev forward
        curr = next;         // Move curr forward
    }
    return prev;             // New head of the reversed list
}