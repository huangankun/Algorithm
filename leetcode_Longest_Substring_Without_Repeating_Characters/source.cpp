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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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