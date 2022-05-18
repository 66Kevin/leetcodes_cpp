class Solution {
public:
    vector<string> ret;
    // 通过预排序+剪枝来去重
    vector<string> permutation(string s) {
        vector<bool> visited(s.size(), false);
        string path = "";
        // 排序后使得相同元素前后排列方便去重
        sort(s.begin(), s.end());
        dfs(path, s, visited);
        return ret;
    }

    void dfs(string &path, string &s, vector<bool> &visited){
        if(path.size()==s.size()){
            ret.push_back(path);
            return;
        }
        for(int i=0; i<s.size(); i++){
            // 当前位置已访问，已在当前path中
            if(visited[i]) continue;
            // 前一个位置的字符与当前位置相同，且前一个位置字符已经访问过
            if(i > 0 && s[i-1] == s[i] && visited[i-1] == false) continue;

            visited[i] = true;
            path += s[i];

            dfs(path, s, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};
