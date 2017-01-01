class Solution
{
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1) return s;
		int len = s.size(), k = 0, interval = (numRows << 1) - 2;
		string res(len, ' ');
		for (int j = 0; j < len; j += interval)		//处理第一行
			res[k++] = s[j];
		for (int i = 1; i < numRows - 1; i++)//处理中间行
			for (int j = i; j < len; j += (interval - 2 * i))
				res[k++] = s[j];
		for (int j = numRows - 1; j < len; j += interval)//处理第三行
			res[k++] = s[j];
		return res;
	}
};