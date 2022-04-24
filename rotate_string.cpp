class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string :: npos;
    }
};
//只需要检查 goal 是否为s+s 的子字符串即可
