class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-1-i]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=ans[i][j];
            }
        }
    }
};