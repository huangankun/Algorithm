/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
			 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		int n = s.length();
		int ans = 0;
		unordered_map<char, int> m;
		for (int i = 0, j = 0; j < n; j++)
		{
			unordered_map<char, int>::const_iterator got = m.find(s[j]);
			if (got != m.end())
			{
				int index = m.at(s[j]);
				i = index > i ? index : i;
			}
			ans = ans > j - i + 1 ? ans : j - i + 1;
			m[s[j]] = j + 1;
		}
		return ans;
	}
};