/**
 * Problem: Insert Greatest Common Divisors in Linked List
 * Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
 * Difficulty: Medium
 *
 * Approach:
 * 1. Traverse the linked list node by node.
 * 2. For every pair of adjacent nodes:
 *      - Compute the GCD of their values.
 * 3. Create a new node containing the computed GCD.
 * 4. Insert this new node between the two original nodes.
 * 5. Move the pointer ahead and continue until the end of the list.
 *
 * GCD Calculation:
 * - Uses subtraction-based Euclidean Algorithm.
 * - Repeatedly subtract the smaller value from the larger
 *   until both become equal.
 *
 * Time Complexity: O(n * log(max(a, b)))
 *   n = number of nodes
 *   GCD computation takes logarithmic time in worst case.
 *
 * Space Complexity: O(n)
 *   Because we insert one extra node between every pair.*/

# include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode * next;
};
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode* ptr = head;
    while (ptr->next != NULL) {
        int gcd;
        int a = ptr->val;
        int b = ptr->next->val;
        if (a == 0) {
            gcd = b;
        }
        else if (b == 0) {
            gcd = a;
        }
        else {
            while (a != b) {
                if (a > b) {
                    a = a - b;
                }
                else {
                    b = b - a;
                }
            }
            gcd = a;
        }
        struct ListNode* ptr2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* temp = ptr->next;
        ptr->next = ptr2;
        ptr2->next = temp;
        ptr2->val = gcd;
        ptr = temp;   
    }
    return head;
}