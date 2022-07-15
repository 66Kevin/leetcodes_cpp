class Solution {
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> que;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1) que.push({i, j});
            }
        }
        
        //没有陆地或海洋的情况返回-1
        if(que.size() == 0 || que.size() == n*n) return -1;
        int distance = -1;
        while(!que.empty()){
            distance ++;
            int m = que.size();
            for(int i = 0; i < m; ++i){
                auto cur = que.front(); que.pop();
                for(auto& d : directions){
                    int x = cur.first + d[0];
                    int y = cur.second + d[1];
                    // 如果搜索到的新坐标超出范围/陆地/已经遍历过，则不搜索了
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 0) {
                        continue;
                    }
                    grid[x][y] = 2;
                    que.push({x, y});
                }
            }
        }
        return distance;
    }
};
