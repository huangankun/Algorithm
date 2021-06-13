/*
 * @lc app=leetcode.cn id=206 lang=golang
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	// //这个地方不能够使用&ListNode{}结构，会自动初始化
	// var reverse *ListNode
	// curHead := head
	// for head != nil {
	// 	curHead = head.Next
	// 	head.Next = reverse
	// 	reverse = head
	// 	head = curHead
	// }
	// return reverse

	//递归
	if head == nil || head.Next == nil {
		return head
	}

	curHead := reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil
	return curHead
}

// @lc code=end

