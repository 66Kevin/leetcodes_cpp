class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(0,0,visited,m,n,k);
    }
    
private:    
    int dfs(int i, int j, vector<vector<bool>> &visited, int m, int n, int k) {
        int cnt = 0;
        if(i < 0 || i >= m || j < 0 || j >= n || getSum(i, j) > k || visited[i][j]) return false;
        visited[i][j] = true;
        cnt = 1 + dfs(i-1,j,visited,m,n,k) + dfs(i+1,j,visited,m,n,k) 
                + dfs(i,j-1,visited,m,n,k) + dfs(i,j+1,visited,m,n,k);

       return cnt;
   }

    int getSum(int i, int j) {
        int sum = 0;
        while(i != 0) {   // 一直不断除以10，最后会变成0，因为/会向0取整（只保留整数位）
            sum += i % 10;
            i = i / 10; // 当都为整数时，向0取整，就是去掉小数点
        }
        while(j != 0) {  
            sum += j % 10;
            j = j / 10;
        }
        return sum;
    }
  
};
