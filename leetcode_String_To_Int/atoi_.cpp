class Solution {
public:
    // 字符串转int，注意判断超出Int范围
    int myAtoi(string str) {
        if (str == "") return 0;
        // 去首尾空格
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
        
        int i = 0, len = str.length(), sign = 1;
        while ( i < len && str[i] == ' ') i++;
        if (i == len) return 0;
        if (str[i] == '+') {
            sign = 1;
            i++;
        } else 
            if (str[i] == '-') {
                sign = -1;
                i++;
            }
        // 转换结果可能超出int范围，使用long long作为转换后接收变量的类型
        long long ret = 0;
        for (; i < len; i++) {
            if (str[i] < '0' || str[i] > '9') break;
            ret = ret * 10 + (str[i] - '0');
            if (ret > INT_MAX) break;
        }
        ret *= sign;
        if (ret > INT_MAX) return INT_MAX;
        if (ret < INT_MIN) return INT_MIN;
        return ret;
    }
};