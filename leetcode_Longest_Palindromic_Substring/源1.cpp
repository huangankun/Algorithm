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