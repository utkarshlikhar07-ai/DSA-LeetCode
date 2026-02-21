// Problem: Median of Two Sorted Arrays
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=problem-list-v2&envId=array
// Difficulty: Hard
// Approach: Merge + Sort (Brute Force)
// Time Complexity: O((m+n)^2)  // Because of Bubble Sort
// Space Complexity: O(m+n)
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int merged[total], l = nums1Size;
    for (int i = 0; i < nums1Size; i++)
        merged[i] = nums1[i];
    for (int j = 0; j < nums2Size; j++)
        merged[l++] = nums2[j];
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (merged[j] > merged[j + 1]) {
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }
    if (total % 2 == 0)
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    else
        return merged[total / 2];
}
