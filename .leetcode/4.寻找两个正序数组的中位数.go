/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	//合并后进行排序，最暴力简单的方法
	//intList := [] int {2, 4, 3, 5, 7, 6, 9, 8, 1, 0}
	//float8List := [] float64 {4.2, 5.9, 12.3, 10.0, 50.4, 99.9, 31.4, 27.81828, 3.14}
	// float4List := [] float32 {4.2, 5.9, 12.3, 10.0, 50.4, 99.9, 31.4, 27.81828, 3.14}    // no function : sort.Float32s
	//stringList := [] string {"a", "c", "b", "d", "f", "i", "z", "x", "w", "y"}
	//sort.Ints(intList)
	//sort.Float64s(float8List)
	// sort.Strings(stringList)
	newNum := append(nums1, nums2...)
	//sort可以直接对int进行排序
	sort.Ints(newNum)
	newLength := len(newNum)
	var res float64
	if newLength%2 == 0 {
		res = (float64(newNum[newLength/2-1]) + float64(newNum[newLength/2])) / 2
		return res
	} else {
		res = float64(newNum[newLength/2])
		return res
	}
}

// @lc code=end

