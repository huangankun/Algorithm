/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
// func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
// 	//合并后进行排序，最暴力简单的方法
// 	//intList := [] int {2, 4, 3, 5, 7, 6, 9, 8, 1, 0}
// 	//float8List := [] float64 {4.2, 5.9, 12.3, 10.0, 50.4, 99.9, 31.4, 27.81828, 3.14}
// 	// float4List := [] float32 {4.2, 5.9, 12.3, 10.0, 50.4, 99.9, 31.4, 27.81828, 3.14}    // no function : sort.Float32s
// 	//stringList := [] string {"a", "c", "b", "d", "f", "i", "z", "x", "w", "y"}
// 	//sort.Ints(intList)
// 	//sort.Float64s(float8List)
// 	// sort.Strings(stringList)
// 	newNum := append(nums1, nums2...)
// 	//sort可以直接对int进行排序
// 	sort.Ints(newNum)
// 	newLength := len(newNum)
// 	var res float64
// 	if newLength%2 == 0 {
// 		res = (float64(newNum[newLength/2-1]) + float64(newNum[newLength/2])) / 2
// 		return res
// 	} else {
// 		res = float64(newNum[newLength/2])
// 		return res
// 	}
// }

// 复杂度分析

// 时间复杂度：O(logmin(m,n)))，其中m和n是数组的长度，查找的区间是[0,m]而区间的每次循环都会在长度减少到原来的
// 一半，所以只需要执行logm次循环。由于每次循环中的操作次数是常数，所以时间复杂度为O(logm)而由于会交换mn的长度
// 取m为较小值因此时间复杂度为O(logmin(m,n))
// 空间复杂度：O(1)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums1) > len(nums2) {
		return findMedianSortedArrays(nums2, nums1)
	}
	m, n := len(nums1), len(nums2)
	left, right := 0, m
	median1, median2 := 0, 0
	for left <= right {
		i := (left + right) / 2
		j := (m+n+1)/2 - i
		nums_im1 := math.MinInt32
		if i != 0 {
			nums_im1 = nums1[i-1]
		}
		nums_i := math.MaxInt32
		if i != m {
			nums_i = nums1[i]
		}
		nums_jm1 := math.MinInt32
		if j != 0 {
			nums_jm1 = nums2[j-1]
		}
		nums_j := math.MaxInt32
		if j != n {
			nums_j = nums2[j]
		}
		if nums_im1 <= nums_j {
			median1 = max(nums_im1, nums_jm1)
			median2 = min(nums_i, nums_j)
			left = i + 1
		} else {
			right = i - 1
		}
	}
	if (m+n)%2 == 0 {
		return float64(median1+median2) / 2.0
	}
	return float64(median1)
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// @lc code=end

