/**
 * Problem: Remove Nth Node From End of List
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Difficulty: Medium
 *
 * Approach (Two-Pass Method):
 * 1. Traverse the linked list once to count total number of nodes.
 * 2. If n equals the total count:
 *      - Remove the head node.
 * 3. Otherwise:
 *      - Find the (count - n)th node from the beginning.
 *      - Delete its next node.
 *
 * Why count - n?
 * If the list has 'count' nodes,
 * the nth node from the end is the (count - n)th node from the start.
 *
 * Time Complexity: O(n)
 *   - First traversal to count nodes → O(n)
 *   - Second traversal to reach deletion point → O(n)
 *
 * Space Complexity: O(1)
 *   - No extra data structures used.
 *
 * Edge Cases Handled:
 * - Empty list (head == NULL)
 * - Deleting the head node
 */

#include <stdlib.h>
# include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    int count = 0;
    struct ListNode* ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    if (n == count) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int index = count - n;
    struct ListNode* ptr2 = head;
    for (int i = 1; i < index; i++) {
        ptr2 = ptr2->next;
    }
    struct ListNode* temp = ptr2->next;
    ptr2->next = temp->next;
    free(temp);
    return head;
}
