/*
 * @lc app=leetcode.cn id=322 lang=golang
 *
 * [322] 零钱兑换
 */

// @lc code=start
func coinChange(coins []int, amount int) int {
	sol := make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		sol[i] = -1
		for j := 0; j < len(coins); j++ {
			if i >= coins[j] && sol[i-coins[j]] < sol[i] {
				sol[i] = sol[i-coins[j]]
			}
		}
	}
	return sol[amount]
}

// @lc code=end

