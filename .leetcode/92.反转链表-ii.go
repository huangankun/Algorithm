/*
 * @lc app=leetcode.cn id=92 lang=golang
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	// 思路：先遍历到m处，翻转，再拼接后续，注意指针处理
	// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
	if head == nil {
		return head
	}
	// 头部变化所以使用dummy node
	dummy := &ListNode{Val: 0}
	dummy.Next = head
	head = dummy
	// 最开始：0->1->2->3->4->5->nil
	var pre *ListNode
	var i = 0
	for i < m {
		pre = head
		head = head.Next
		i++
	}
	// 遍历之后： 1(pre)->2(head)->3->4->5->NULL
	// i = 1
	var j = i
	var next *ListNode
	// 用于中间节点连接
	var mid = head
	for head != nil && j <= n {
		// 第一次循环： 1 nil<-2 3->4->5->nil
		temp := head.Next
		head.Next = next
		next = head
		head = temp
		j++
	}
	// 循环需要执行四次
	// 循环结束：1 nil<-2<-3<-4 5(head)->nil
	pre.Next = next
	mid.Next = head
	return dummy.Next
}

// @lc code=end

