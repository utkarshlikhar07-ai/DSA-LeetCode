/**
 * Problem: Swap Nodes in Pairs
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 * Difficulty: Medium
 *
 * Approach (Value Swapping Method):
 * 1. Traverse the linked list two nodes at a time.
 * 2. Swap the values of the current node and the next node.
 * 3. Move the pointer forward by two nodes.
 * 4. Continue until we reach the end of the list.
 *
 * Important:
 * - This solution swaps node VALUES, not actual nodes.
 * - Structure of the linked list remains unchanged.
 *
 * Time Complexity: O(n)
 *   - Each node is visited once.
 *
 * Space Complexity: O(1)
 *   - No extra space used.
 *
 * Edge Cases Handled:
 * - Empty list (head == NULL)
 * - Single node list (no swap possible)
 */
# include <stdio.h>
# include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
  };

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* ptr = head;
    int temp;
    while (ptr != NULL && ptr->next != NULL) {
        temp = ptr->val;
        ptr->val = ptr->next->val;
        ptr->next->val = temp;
        ptr = ptr->next->next;  
    }
    return head;
}