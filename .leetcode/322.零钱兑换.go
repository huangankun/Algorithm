/*
 * @lc app=leetcode.cn id=322 lang=golang
 *
 * [322] 零钱兑换
 */

// @lc code=start
func coinChange(coins []int, amount int) int {
	//设置初始值为-1时，由于每次需要取解决方法中的较小值，需要排除特殊情况
	// sol := make([]int, amount+1)
	// for i := 1; i <= amount; i++ {
	// 	sol[i] = -1
	// 	for j := 0; j < len(coins); j++ {
	// 		if i > coins[j] && sol[i-coins[j]] != -1 {
	// 			if sol[i] == -1 {
	// 				sol[i] = sol[i-coins[j]] + 1
	// 			} else if sol[i-coins[j]]+1 < sol[i] {
	// 				sol[i] = sol[i-coins[j]] + 1
	// 			}
	// 		} else if i == coins[j] {
	// 			sol[i] = 1
	// 		}
	// 	}
	// }
	// return sol[amount]

	//直接将初始值设为最大值，则比较符合思维方式
	if amount < 1 && len(coins) < 1 {
		return -1
	}
	memo := make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		memo[i] = math.MaxInt32
		for _, c := range coins {
			if i >= c && memo[i] > memo[i-c]+1 {
				memo[i] = memo[i-c] + 1
			}
		}
	}
	if memo[amount] == math.MaxInt32 {
		return -1
	}
	return memo[amount]
}

// @lc code=end

