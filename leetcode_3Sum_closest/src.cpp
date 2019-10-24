/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		int res;
		res = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size() - 2; i++)
			for (int j = i + 1; j < nums.size() - 1; j++)
				for (int k = j + 1; k < nums.size(); k++)
					if (abs(nums[i] + nums[j] + nums[k] - target) <= abs(res - target))
						res = nums[i] + nums[j] + nums[k];
		return res;
	}
};