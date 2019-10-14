/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//暴力解法1，直接遍历子串，然后判断子串是否为回文串，如果是回文串则记录大小，其中时间复杂度是O(3^n)，子串个数为n(n-1)/2
class solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		string ans;
		int max;
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j <= len; ++j)
			{
				string tmp = s.substr(i, j - i + 1);
				if (isPalindromic(tmp))
				{
					ans = tmp;
					max = max > tmp.length() ? max : tmp.length();
				}
			}
		}
		return ans;
	}
	bool isPalindromic(string s) {
		int len = s.length();
		for (int i = 0; i < len / 2; ++i)
		{
			if (s[i] != s[len - i + 1])
			{
				return false;
			}
		}
		return true;
	}
};

//最长公共子串的求法
class solutionDesginProcess {
public:
	string longestPalindrome(string s) 
	{
		if (s == "")
			return "";
		string origin = s;
		string reverse = s;
		std::reverse(reverse.begin(), reverse.end());
		int len = s.length();
		int arr[len][len];
		memset(arr, 0, sizeof(arr));
		int maxLen = 0;
		int maxEnd = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (origin[i] == reverse[j])
				{
					if (i == 0 || j == 0) {
						arr[i][j] = 1;
					}
					else {
						arr[i][j] = arr[i - 1][j - 1] + 1;
					}
				}
				if (arr[i][j] > maxLen)
				{
					int beforeRev = len - 1 - j;
					if (beforeRev + arr[i][j] - 1 == i)
					{
						maxLen = arr[i][j];
						maxEnd = i;
					}
				}
			}
		}
		return s.substr(maxEnd - maxLen + 1, maxLen);
	}
};

//动态规划空间优化版本
class solutionDesginProcessPro
{
public:
	string longestPalindrome(string s) {
		if (s == "")
		{
			return "";
		}
		string origin = s;
		string reverse = s;
		std::reverse(reverse.begin(), reverse.end());
		int len = s.length();
		int arr[len] = { 0 };
		int maxLen = 0;
		int maxEnd = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = len -1; j >= 0; j--)
			{
				if (origin[i] == reverse[j])
				{

					if (i == 0 || j == 0)
					{
						arr[j] = 1;
					}
					else
					{
						arr[j] = arr[j - 1] + 1;
					}
				}
				else
					arr[j] = 0;
				if (arr[j] > maxLen)
				{
					int breforeRev = len - 1 - j;
					if (breforeRev + arr[j] - 1 == i)
					{
						maxLen = arr[j];
						maxEnd = i;
					}
				}
			}
		}
		return s.substr(maxEnd - maxLen + 1, maxLen);
	}
}

//暴力解法优化版本
class solutionDesginProcessNext {
public:
	longestPalindrome(string s)
	{
		if (s == "")
		{
			return s;
		}
		int len = s.length();
		bool p[len][len];
		memset(p, 0, sizeof(p));
		int maxLen = 0;
		string maxPal = "";
		for (int tmp = 1; tmp < len; ++tmp)
		{
			for (int start = 0; start < len; ++start)
			{
				int end = start + tmp - 1;
				if (end > tmp)	//下标已经越界，结束本次循环
				{
					break;
				}
				p[start][end] = ((tmp == 1 || tmp == 2 || p[start + 1][end - 1]) && (s[start] == s[end]));
				if (p[start][end] && tmp > maxLen)
				{
					maxPal = s.substr(start, end - start + 1);
				}
			}
		}
		return maxPal;
	}

	longestPalindromeNext(string s) {
		if (s == "")
		{
			return s;
		}
		int len = s.length();
		string res = "";
		bool p[len];
		for (int i = len; i >=0; i--)
		{
			for (int j = len-1; j>=i;j--)
			{
				p[j] = s[i] == s[j] && (j - i < 3 || p[j - 1]);
				if (p[j] && j - i + 1 > res.length())
				{
					res = s.substr(i, j + 1 - i);
				}
			}
		}
		return res;
	}

	longestPalindromeCenter(string s) {
		if (s == nullptr || s.length() < 1)
		{
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = len1 > len2 ? len1 : len2;
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end + 1 - start);
	}

	int expandAroundCenter(string s, int left, int right) {
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}
};

//扩展中心解法

