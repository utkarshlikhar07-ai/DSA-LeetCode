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
