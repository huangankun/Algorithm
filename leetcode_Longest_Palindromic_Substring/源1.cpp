/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-palindromic-substring
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


//�����ⷨ1��ֱ�ӱ����Ӵ���Ȼ���ж��Ӵ��Ƿ�Ϊ���Ĵ�������ǻ��Ĵ����¼��С������ʱ�临�Ӷ���O(3^n)���Ӵ�����Ϊn(n-1)/2
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

//��̬�滮�ռ��Ż��汾
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