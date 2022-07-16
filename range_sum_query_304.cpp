class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        integeral=vector<vector<int>>(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                integeral[i][j]=integeral[i-1][j]+integeral[i][j-1]-integeral[i-1][j-1]+matrix[i-1][j-1];
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return integeral[row2+1][col2+1]-integeral[row1][col2+1]-integeral[row2+1][col1]+integeral[row1][col1];
    }
private:
    vector<vector<int>> integeral;
};

