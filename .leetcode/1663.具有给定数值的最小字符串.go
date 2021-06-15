/*
 * @lc app=leetcode.cn id=1663 lang=golang
 *
 * [1663] 具有给定数值的最小字符串
 */

// @lc code=start
func getSmallestString(n int, k int) string {
	str := "abcdefghijklmnopqrstuvwxyz"
	res := make([]byte, n)
	for i := n; i > 0; i-- {
		for x := 25; x >= 0; x-- {
			if k-x-1 > i-1 {
				res[i-1] = str[x]
				k = k - x - 1
				break
			} else if k-x-1 == i-1 {
				res[i-1] = str[x]
				for j := 0; j < i-1; j++ {
					res[j] = 'a'
				}
				return string(res)
			}
		}
	}
	return string(res)
}

// @lc code=end

