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