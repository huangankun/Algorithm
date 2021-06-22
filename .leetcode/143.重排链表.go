/*
 * @lc app=leetcode.cn id=143 lang=golang
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode) {
	if head == nil {
		return
	}
	mid := getMid(head)
	tail := reverseList(mid.Next)
	mid.Next = nil
	head = mergeTwoLists(head, tail)
}

func getMid(head *ListNode) *ListNode {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	return slow
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{Val: 0}
	head := dummy
	toggle := true
	for l1 != nil && l2 != nil {
		// 节点切换
		if toggle {
			head.Next = l1
			l1 = l1.Next
		} else {
			head.Next = l2
			l2 = l2.Next
		}
		toggle = !toggle
		head = head.Next
	}
	// 连接l1 未处理完节点
	for l1 != nil {
		head.Next = l1
		head = head.Next
		l1 = l1.Next
	}
	// 连接l2 未处理完节点
	for l2 != nil {
		head.Next = l2
		head = head.Next
		l2 = l2.Next
	}
	return dummy.Next
}
func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	for head != nil {
		// 保存当前head.Next节点，防止重新赋值后被覆盖
		// 一轮之后状态：nil<-1 2->3->4
		//              prev   head
		temp := head.Next
		head.Next = prev
		// pre 移动
		prev = head
		// head 移动
		head = temp
	}
	return prev
}

// @lc code=end

