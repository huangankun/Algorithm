/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	//利用哈希记录该元素是否出现，最大空进复杂度是ASCII字符数量
	m := map[byte]int{}
	length := len(s)
	//滑动窗口右指针
	r, result := -1, 0
	//遍历字符串，i滑动窗口左指针，时间复杂度是N
	for i := 0; i < length; i++ {
		//当左指针不指向首元素时需要把哈希表中已经记录的元素清除
		if i != 0 {
			delete(m, s[i-1])
		}
		//右指针窗口扩容直到遇到在哈希表中的重复元素或者右指针指向最后一个元素
		for r+1 < length && m[s[r+1]] == 0 {
			m[s[r+1]]++
			r++
		}
		//取两者中大值
		result = max(result, r-i+1)
	}
	return result
}

func max(res, cur int) int {
	if res > cur {
		return res
	} else {
		return cur
	}
}

// @lc code=end

