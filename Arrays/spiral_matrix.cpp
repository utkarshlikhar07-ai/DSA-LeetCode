/*
Problem: Spiral Matrix
Link: https://leetcode.com/problems/spiral-matrix/
Difficulty: Medium
Approach:
1. Maintain four boundaries:
   - startingRow (top boundary)
   - endingRow (bottom boundary)
   - startingCol (left boundary)
   - endingCol (right boundary)
2. Traverse the matrix in 4 steps repeatedly:
   a) Left → Right across the top row
   b) Top → Bottom along the right column
   c) Right → Left across the bottom row
   d) Bottom → Top along the left column
3. After completing one full layer:
   - Move top boundary down
   - Move right boundary left
   - Move bottom boundary up
   - Move left boundary right
4. Continue until all elements are added to result.
Time Complexity: O(m * n)
  m = number of rows
  n = number of columns
  Each element is visited exactly once.
Space Complexity: O(m * n)
  Extra space used to store the result.
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int rows = matrix.size();
        int col = matrix[0].size();

        int total = rows * col;
        int count = 0;

        int startingrow = 0;
        int startingcol = 0;
        int endingrow = rows - 1;
        int endingcol = col - 1;

        while (count < total) {
            for (int j = startingcol; j <= endingcol && count < total; j++) {
                ans.push_back(matrix[startingrow][j]);
                count++;
            }
            startingrow++;      
            for (int i = startingrow; i <= endingrow && count < total; i++) {
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;  
            for (int k = endingcol; k >= startingcol && count < total; k--) {
                ans.push_back(matrix[endingrow][k]);
                count++;
            }
            endingrow--;   
            for (int f = endingrow; f >= startingrow && count < total; f--) {
                ans.push_back(matrix[f][startingcol]);
                count++;
            }
            startingcol++;
        }

        return ans;
    }
};
