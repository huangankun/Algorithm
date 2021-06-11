/*
 * @lc app=leetcode.cn id=946 lang=golang
 *
 * [946] 验证栈序列
 */
//时间复杂度O(n)
//空间复杂度O(n)
// @lc code=start
func validateStackSequences(pushed []int, popped []int) bool {
	lst := []int{}
	for _, v := range pushed {
		lst = append(lst, v)
		for len(lst) > 0 && lst[len(lst)-1] == popped[0] {
			popped = popped[1:]
			lst = lst[:len(lst)-1]
		}
	}
	if len(lst) == 0 {
		return true
	} else {
		return false
	}
}

// @lc code=end

