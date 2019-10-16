//Given n non - negative integers a1, a2, ..., an , where each represents a point at coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.
//	The above vertical lines are represented by array[1, 8, 6, 2, 5, 4, 8, 3, 7].In this case, the max area of water(blue section) the container can contain is 49.
//	Example:
//
//	Input: [1, 8, 6, 2, 5, 4, 8, 3, 7]
//		Output : 49
//
//		来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/container-with-most-water
//		   著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//暴力遍历解决法：
class Solution {
public:
	int maxArea(vector<int>& height)
	{
		int max = 0;
		for (int i = 0; i < height.size() - 1; i++)
			for (int j = i + 1; j < height.size(); j++) {
				if (height[j] > height[i]) {
					int area = height[i] * (j - i);
					max = area > max ? area : max;
				}
				else {
					int area = height[j] * (j - i);
					max = area > max ? area : max;
				}
			}
		return max;
	}
};

//双指针法
class Solution2 {
public:
	int maxArea(vector<int>& height)
	{
		int max = 0, l = 0, r = height.size() - 1;
		while (l < r) {
			int area = 0;
			if (height[l] > height[r]) {
				area = (r - l)*height[r];
				r--;
			}
			else {
				area = (r - l)*height[l];
				l++;
			}
			max = max > area ? max : area;
		}
		return max;
	}
};