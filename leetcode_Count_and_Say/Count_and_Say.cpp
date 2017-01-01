/*
***************代码摘自——九章算法************
使用stringstream对象简化类型转换
C++标准库
*/

class Solution {
public:
	string int_to_string(int j)
	{
		stringstream in;
		in << j;
		string temp;
		in >> temp;
		return temp;
	}
	string genate(string s) {
		string now;
		int j = 0;
		for (int i = 0; i < s.size(); i += j)//i用来当做最后一个相同数的下标
		{
			for (j = 0; j + i < s.size(); j++)//j用来统计当前相同值的数的个数
				if (s[i] != s[i + j])
					break;
			now = now + int_to_string(j) + s[i];//每次找到最后一个相同数的时候记下个数和数的值，进入下一次循环
		}
		return now;
	}

	string countAndSay(int n)
	{
		string s("1");
		while (--n)
		{
			s = genate(s);
		}
		return s;
	}
};

void int main() {
	Solution sol;
	string str = sol.countAndSay(111221);
}