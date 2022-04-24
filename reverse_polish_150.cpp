class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
        vector<int> stk;
        for (string token : tokens) { 
            if (token == "+" || token == "-" || token == "*" || token == "/") { 
                int num1 = stk.back();
                stk.pop_back();
                int num2 = stk.back();
                stk.pop_back(); 
                if (token == "+") stk.push_back(num1 + num2);
                if (token == "-") stk.push_back(num2 - num1);
                if (token == "*") stk.push_back(num1 * num2);
                if (token == "/") stk.push_back(num2 / num1);
            } else {stk.push_back(stoi(token));} // 如果是正常数的话转化成INT(标准库stoi函数)后塞进去
        }
        return stk.back();
    }
};
