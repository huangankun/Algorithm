/*
 * @lc app=leetcode.cn id=148 lang=golang
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

//合并两个有序链表
// func merge(head1, head2 *ListNode) *ListNode {
// 	//采用哑结点进行排序
// 	dummyHead := &ListNode{}
// 	temp, temp1, temp2 := dummyHead, head1, head2
// 	for temp1 != nil && temp2 != nil {
// 		if temp1.Val <= temp2.Val {
// 			temp.Next = temp1
// 			temp1 = temp1.Next
// 		} else {
// 			temp.Next = temp2
// 			temp2 = temp2.Next
// 		}
// 		temp = temp.Next
// 	}
// 	if temp1 != nil {
// 		temp.Next = temp1
// 	} else if temp2 != nil {
// 		temp.Next = temp2
// 	}
// 	return dummyHead.Next
// }

// //归并排序
// func sort(head, tail *ListNode) *ListNode {
// 	if head == nil {
// 		return head
// 	}

// 	if head.Next == tail {
// 		head.Next = nil
// 		return head
// 	}

// 	//快慢指针查找中间节点
// 	slow, fast := head, head
// 	for fast != tail {
// 		slow = slow.Next
// 		fast = fast.Next
// 		if fast != tail {
// 			fast = fast.Next
// 		}
// 	}

// 	//慢指针对应的结点为中间结点
// 	mid := slow

// 	//递归对头和中间结点进行合并
// 	return merge(sort(head, mid), sort(mid, tail))
// }

// func sortList(head *ListNode) *ListNode {
// 	return sort(head, nil)
// }

//自顶向下的递归,n为链表长度
//时间复杂度 o(nlogn)
//空间复杂度 o(logn)，空间复杂度主要取决于递归使用的栈空间

//自顶向下的递归,n为链表长度
//时间复杂度 o(nlogn)
//空间复杂度 o(1)

func merge(head1, head2 *ListNode) *ListNode {
	dummyHead := &ListNode{}
	temp, temp1, temp2 := dummyHead, head1, head2
	for temp1 != nil && temp2 != nil {
		if temp1.Val <= temp2.Val {
			temp.Next = temp1
			temp1 = temp1.Next
		} else {
			temp.Next = temp2
			temp2 = temp2.Next
		}
		temp = temp.Next
	}
	if temp1 != nil {
		temp.Next = temp1
	} else if temp2 != nil {
		temp.Next = temp2
	}
	return dummyHead.Next
}

func sortList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	length := 0
	for node := head; node != nil; node = node.Next {
		length++
	}

	dummyHead := &ListNode{Next: head}
	for subLength := 1; subLength < length; subLength <<= 1 {
		prev, cur := dummyHead, dummyHead.Next
		for cur != nil {
			head1 := cur
			for i := 1; i < subLength && cur.Next != nil; i++ {
				cur = cur.Next
			}

			head2 := cur.Next
			cur.Next = nil
			cur = head2
			for i := 1; i < subLength && cur != nil && cur.Next != nil; i++ {
				cur = cur.Next
			}

			var next *ListNode
			if cur != nil {
				next = cur.Next
				cur.Next = nil
			}

			prev.Next = merge(head1, head2)

			for prev.Next != nil {
				prev = prev.Next
			}
			cur = next
		}
	}
	return dummyHead.Next
}

// @lc code=end

