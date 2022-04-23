class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        /* 判断数组不为空 */
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int row = 0;
        int column = matrix[0].size() - 1;

        while (row < matrix.size() && column >= 0) {
            /* 获取当前元素 */
            int num = matrix[row][column];
            /* 遍历数组 */
            if (num == target) {
                return true;
            } else if (num > target) {
                column--;
            } else {
                row++;
            }
        }
        return false;
    }
};
