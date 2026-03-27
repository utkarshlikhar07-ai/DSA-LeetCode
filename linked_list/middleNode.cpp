/*
 * LeetCode Link: https://leetcode.com/problems/middle-of-the-linked-list/
 * * Question Detail: 
 * Given the head of a singly linked list, return the middle node of the linked list. 
 * If there are two middle nodes, return the second middle node.
 *
 * Approach:
 * The solution utilizes the "Fast and Slow Pointer" technique. Two pointers, 
 * 'slow' and 'fast', both start at the head. In each iteration, 'slow' moves 
 * one step while 'fast' moves two steps. By the time 'fast' reaches the end 
 * of the list, 'slow' will be positioned exactly at the middle.
 *
 * Difficulty: Easy
 * * Time Complexity: O(n) - We traverse the list once.
 * Space Complexity: O(1) - Only two pointers are used, regardless of list size.
 */

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

#include <bits/stdc++.h>
using namespace std;
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}