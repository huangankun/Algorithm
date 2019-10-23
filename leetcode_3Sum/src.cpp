/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
//暴力解法但是不被AC，时间超出限制
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			for (int j = i + 1; j < nums.size() - 1; j++)
			{
				for (int k = j + 1; k < nums.size(); k++)
				{
					if (nums[i] + nums[j] + nums[k] == 0)
					{
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[k]);
						res.push_back(tmp);
					}
				}
			}
		}
		return res;
	}
};

//解法 双指针法
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<vector<int> > res;
		for (int i = 0; i < N - 2; ++i) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int l = i + 1;
			int r = N - 1;
			while (l < r) {
				int s = nums[i] + nums[l] + nums[r];
				if (s > 0) {
					--r;
				}
				else if (s < 0) {
					++l;
				}
				else {
					res.push_back({ nums[i], nums[l], nums[r] });
					while (l < r && nums[l] == nums[++l]);
					while (l < r && nums[r] == nums[--r]);
				}
			}
		}
		return res;
	}
}