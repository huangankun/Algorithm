/*
 * @lc app=leetcode.cn id=51 lang=golang
 *
 * [51] N 皇后
 */

// @lc code=start
//存储解决方法
//时间复杂度：O(N!)，其中 NN 是皇后数量。
//空间复杂度：O(N)，其中 NN 是皇后数量。
//空间复杂度主要取决于递归调用层数、记录每行放置的皇后的列下标的数组以及三个集合，
//递归调用层数不会超过 N，数组的长度为 N，每个集合的元素个数都不会超过 N
var solutions [][]string

//朱芳芳
func solveNQueens(n int) [][]string {
	//解决图解
	solutions = [][]string{}
	//n皇后
	queens := make([]int, n)
	//初始化N皇后
	for i := 0; i < n; i++ {
		queens[i] = -1
	}
	//初始化每一列，都置位false
	columns := map[int]bool{}
	diagonals1, diagonals2 := map[int]bool{}, map[int]bool{}
	backtrack(queens, n, 0, columns, diagonals1, diagonals2)
	return solutions
}

//递归处理
func backtrack(queens []int, n, row int, columns, diagonals1, diagonals2 map[int]bool) {
	//当前处理最后一行，找到解决方法直接返回
	if row == n {
		board := generateBoard(queens, n)
		solutions = append(solutions, board)
		return
	}
	//从第0列开始判断，直到n-1列
	for i := 0; i < n; i++ {
		//判断当前第row行，第i列是否可用，如果不可用则将当前位置值为Q
		if columns[i] {
			continue
		}
		//方向一的斜线为从左上到右下方向，同一条斜线上的每个位置满足行下标与列下标之差相等
		//例如 (0,0)(0,0) 和 (3,3)(3,3) 在同一条方向一的斜线上。
		//因此使用行下标与列下标之差即可明确表示每一条方向一的斜线
		diagonal1 := row - i
		if diagonals1[diagonal1] {
			continue
		}
		//方向二的斜线为从右上到左下方向，同一条斜线上的每个位置满足行下标与列下标之和相等，
		//例如 (3,0)(3,0) 和 (1,2)(1,2) 在同一条方向二的斜线上。
		//因此使用行下标与列下标之和即可明确表示每一条方向二的斜线。
		diagonal2 := row + i
		if diagonals2[diagonal2] {
			continue
		}
		//记录皇后的位置，第row行第i列
		queens[row] = i
		//设置第i列均为true，该列不可再用
		columns[i] = true
		//记录该行的前i行和后i行不可用
		diagonals1[diagonal1], diagonals2[diagonal2] = true, true
		backtrack(queens, n, row+1, columns, diagonals1, diagonals2)
		queens[row] = -1
		delete(columns, i)
		delete(diagonals1, diagonal1)
		delete(diagonals2, diagonal2)
	}
}

//生成第n行的解法
func generateBoard(queens []int, n int) []string {
	board := []string{}
	//第0行开始遍历
	for i := 0; i < n; i++ {
		row := make([]byte, n)
		//从第i行第j列开始设置
		for j := 0; j < n; j++ {
			row[j] = '.'
		}
		row[queens[i]] = 'Q'
		board = append(board, string(row))
	}
	return board
}

// @lc code=end

