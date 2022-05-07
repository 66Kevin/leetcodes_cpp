class Solution {
public:
    bool isNumber(string s) {
        len = s.size();
        if (len == 0) return false;
        int index = 0; 

        // 删除字符串起始位的空格
        while (index < len && s[index] == ' ') {
            ++ index;
        }

        // scanInteger()判断整数，可能以 “+/-” 为起始的 “0~9” 的数位匹配整数部分
        bool numeric = scanInteger(s, index);

        // 处理小数点部分
        if (index < len && s[index] == '.') {
            ++ index;
            // scanUnsigned()用来扫描字符串中 “0~9” 的数位
            // 用 || 的原因
            // 1. 小数可以没有整数部分 
            // 2. 小数点后面可以没有数字
            // 3. 小数点前面或者后面都可以没有符号
            numeric = scanUnsigned(s, index) || numeric;
        }

        // 处理指数部分
        if (index < len && (s[index] == 'e' || s[index] == 'E')) {
            ++ index;
            // scanUnsignedInteger()用来扫描字符串可能出现 “e” 或 “E” 的情况
            // 用 && 的原因
            // 1. 当 “e” 或 “E” 前面没有数字时，字符串不能表示数值
            // 2. 当 “e” 或 “E” 后面没有数字时，字符串不能表示数值
            numeric = scanInteger(s, index) && numeric;
        }

        // 删除字符串末尾位的空格
        while (index < len && s[index] == ' ') {
            ++ index;
        }

        return numeric && (index == len);
    }

private:
    int len;
    bool scanInteger(string &s, int &start) { // 引用传递，s和start是传入实参的别名，共享一个内存空间
        //处理符号 “+/-”
        if (start < len && (s[start] == '+' || s[start] == '-')) {
            ++ start;
        }
        return scanUnsigned(s, start);
    }

    bool scanUnsigned(string &s, int &start) { // 引用传递
        int tmp = start;
        while (start < len && isdigit(s[start])) {
            ++ start;
        }
        return start > tmp;
    }
};

// int a = 1;
// int *x = &a; 	//指针传递，x为指向a的指针
// int &x = a;		//引用传递，x为a的别名
