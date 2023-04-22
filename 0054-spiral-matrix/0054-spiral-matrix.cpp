class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    
//vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> result;
    
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    
    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;
        
        // Print rightmost column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        
        // Print bottom row (if it exists)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        
        // Print leftmost column (if it exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    
    return result;
}
};