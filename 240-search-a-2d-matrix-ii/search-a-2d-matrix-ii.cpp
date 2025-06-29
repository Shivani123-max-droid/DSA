class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowID=0;
        int colID=col-1;
        while(rowID<row && colID>=0){
            int element=matrix[rowID][colID];
            if(element == target){
                return 1;
            } 
            if (element<target){
                rowID++;
            } else {
                colID--;
            }
        }
        return 0;
    }
};