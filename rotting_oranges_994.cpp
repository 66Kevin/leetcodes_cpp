// #include <bits/stdc++. h>
// using namespace std;

class Solution {

        int dirt[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
            int min = 0,fresh = 0;///fresh记录每一个新鲜的水果,min为记录层数
            //队列，保存一对坐标
            queue<pair<int,int>>que;
            //遍历地图
            for(int i = 0;i<grid.size();i++){
                for(int j = 0;j<grid[0].size();j++){
                    if(grid[i][j]==1)fresh++;   //记录新鲜水果的数量
                    else if (grid[i][j] ==2) que.push({i,j});//记录腐烂水果坐标
                }
            }

        while(!que.empty()){
            int n = que.size();
            bool rotten = false; // 为了标记最后一个橙子腐烂
            //遍历队列一层的元素
            for(int i= 0;i<n;i++){
                auto x = que.front();   //保存腐烂元素的坐标
                que.pop();      
                for(auto cur: dirt){
                    int i = x.first + cur[0];   //更新x的坐标
                    int j = x.second + cur[1];  //更新y的坐标
                    //如果遍历的坐标是新鲜的和符合要求的
                    if(i>=0 && i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]==1){
                        grid[i][j] = 2;     //更新坐标
                        que.push({i,j});    //加入队列
                        fresh--;            //新鲜数量减一
                        rotten = true;      //标记遍历完一层
                    }
                }
            }
            if(rotten) min++; 
        }
        return fresh ? -1:min; //如果fresh为0，全完腐烂，返回min
                                //如果fresh不为0，表示还有新鲜的，返回-1
    }
};
