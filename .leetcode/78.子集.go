/*
 * @lc app=leetcode.cn id=78 lang=golang
 *
 * [78] 子集
 */

// @lc code=start

//位运算子集法
//时间复杂度O(n*2^n),一共 2^n个状态，每种状态需要 O(n) 的时间来构造子集
//空间复杂度O(n)
func subsets(nums []int) (ans [][]int) {
	n := len(nums)
	for mask := 0; mask < 1<<n; mask++ {
		set := []int{}
		for i, v := range nums {
			if mask>>i&1 > 0 {
				set = append(set, v)
			}
		}
		ans = append(ans, append([]int(nil), set...))
	}
	return
}

//回溯法
//时间复杂度O(n*2^n)
//空间复杂度O(n)
// func subsets(nums []int) [][]int {
// 	res := [][]int{}
// 	//保存中间结果
// 	list := []int{}
// 	backtrack(nums, 0, list, &res)
// 	return res
// }

// // nums 给定的集合
// // idx 下次添加到集合中的元素位置索引
// // list 临时结果集合(每次需要复制保存)
// // result 最终结果
// func backtrack(nums []int, idx int, list []int, res *[][]int) {
// 	// 把临时结果复制出来保存到最终结果
// 	ans := make([]int, len(list))
// 	copy(ans, list)
// 	*res = append(*res, ans)
// 	// 选择、处理结果、再撤销选择
// 	for i := idx; i < len(nums); i++ {
// 		list = append(list, nums[i])
// 		backtrack(nums, i+1, list, res)
// 		list = list[0 : len(list)-1]
// 	}
// }

// @lc code=end

