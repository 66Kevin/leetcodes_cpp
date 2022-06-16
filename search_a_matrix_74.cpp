class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> tmp;

        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                // cout<< matrix[i][j] << endl;
                tmp.push_back(matrix[i][j]);
            }
        }

        int right = tmp.size();
        int left = 0;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(target < tmp[mid]){
                right = mid;
            }else if(target > tmp[mid]){
                left = mid + 1;
            }else if(target == tmp[mid]){
                return true;
            }
        }

        return false;
    }
};
