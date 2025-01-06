class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cnt = 0, sum = 0;

                int x1, x2, y1, y2;

                x1 = (i-1) > 0 ? (i-1) : 0;
                x2 = (i+1) < m ? (i+1) : m-1;
                y1 = (j-1) > 0 ? (j-1) : 0;
                y2 = (j+1) < n ? (j+1) : n-1;

                for(int x = x1; x <= x2; x++){
                    for(int y = y1; y <= y2; y++){
                        sum += img[x][y];
                        cnt++;
                    }
                }
                ans[i][j] = (sum / cnt);
            }
        }
        return ans;
    }
};

/**

# Complexity Analysis:

Time Complexity: O(m×n×9)=O(m×n), where m,n are the dimensions of the matrix.
For each cell, at most 9 neighbors are processed.

Space Complexity: O(m×n) for the result matrix.

**/
