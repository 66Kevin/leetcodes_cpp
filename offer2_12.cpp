class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        // 返回false的条件：1.越界 2.当前字母不是要寻找的word[k]
        if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        // 返回true的条件：k达到word最后一个字符
        if(k == word.size() - 1) return true;
        // 走过的路变为'\0'，防止重复搜索
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || 
                      dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
        //此时表示该路不同，要把变为'\0'的字符，回溯恢复到原来字符
        board[i][j] = word[k];
        return res;
    }
};
