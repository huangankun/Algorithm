/*
 * @lc app=leetcode.cn id=160 lang=golang
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	lengthA := 0
	aTmp := headA
	for aTmp != nil {
		lengthA++
		aTmp = aTmp.Next
	}

	lengthB := 0
	bTmp := headB
	for bTmp != nil {
		lengthB++
		bTmp = bTmp.Next
	}

	var length int

	//特别注意会忽略掉长度相等时length为0的情况
	if lengthA >= lengthB {
		length = lengthB
		for i := 0; i < lengthA-lengthB; i++ {
			headA = headA.Next
		}
	}

	if lengthB >= lengthA {
		length = lengthA
		for i := 0; i < lengthB-lengthA; i++ {
			headB = headB.Next
		}
	}

	var resNode *ListNode
	for i := 0; i < length; i++ {
		if headA == headB {
			resNode = headA
			return resNode
		}
		headA = headA.Next
		headB = headB.Next
	}
	return resNode
}

// @lc code=end

