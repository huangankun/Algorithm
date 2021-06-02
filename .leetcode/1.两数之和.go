/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	//暴力枚举，时间复杂度为o(n^2)，空间复杂度为o(1)
	// for i := 0; i < len(nums); i++ {
	// 	var res []int
	// 	res = append(res, i)
	// 	for j := i + 1; j < len(nums); j++ {
	// 		if nums[i]+nums[j] == target {
	// 			res = append(res, j)
	// 			return res
	// 		}
	// 	}
	// }

	//时间复杂度为o(n),空间复杂度为o(n)
	// m := map[int]int{}
	// for i := 0; i < len(nums); i++ {
	// 	if p, ok := m[target-nums[i]]; ok {
	// 		return []int{p, i}
	// 	}
	// 	m[nums[i]] = i
	// }
	// return nil

	m := map[int]int{}
	for i, x := range nums {
		if p, ok := m[target-x]; ok {
			return []int{p, i}
		}
		//在遍历过程中直接构建哈希
		m[x] = i
	}
	return nil
}

// @lc code=end

