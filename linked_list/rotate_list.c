/** 
 * Problem: Rotate List
 * Link: https://leetcode.com/problems/rotate-list/
 * Difficulty: Medium
 *
 * Problem Statement:
 * Given the head of a linked list, rotate the list to the right by k places.
 *
 * Approach (Repeated Last Node to Front Method):
 * 1. Count the total number of nodes in the list.
 * 2. Reduce rotations using k % count (since rotating 'count' times
 *    results in the same list).
 * 3. For each rotation:
 *      a) Find the second last node.
 *      b) Delete the last node.
 *      c) Insert that deleted node at the front.
 * 4. Return the updated head.
 *
 * Helper Functions:
 * - last_node(): Returns the second last node.
 * - delete_last(): Deletes last node and returns its value.
 * - insert_front(): Inserts a new node at the beginning.
 *
 * Time Complexity: O(n * k)
 *   - For each rotation, we traverse the list to find the second last node.
 *   - Not optimal for large k.
 *
 * Space Complexity: O(1)
 *   - Only constant extra space used.
 *
 * Edge Cases Handled:
 * - Empty list
 * - Single node list
 * - k greater than list length (handled using modulo)
 */
# include <stdio.h>
# include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
  };
 #include <stdio.h>
#include <stdlib.h>
struct ListNode* last_node(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode* ptr = head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}
int delete_last(struct ListNode* secondLast) {
    int value = secondLast->next->val;
    struct ListNode* temp = secondLast->next;
    secondLast->next = NULL;
    free(temp);
    return value;
}
struct ListNode* insert_front(struct ListNode* head, int value) {
    struct ListNode* newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = head;
    return newNode;
}
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int count=0;
    struct ListNode* ptr5=head;
    while(ptr5!=NULL){
        count++;
        ptr5=ptr5->next;
    }
    if (head == NULL || head->next == NULL)
        return head;
    for (int i = 0; i < k%count; i++) {
        struct ListNode* secondLast = last_node(head);
        if (secondLast == NULL)
            return head;
        int value = delete_last(secondLast);
        head = insert_front(head, value);
    }
    return head;
}