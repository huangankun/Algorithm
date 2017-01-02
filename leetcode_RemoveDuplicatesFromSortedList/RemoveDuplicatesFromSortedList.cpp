/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL)
            return head;
        ListNode* temp = head;
        while(temp->next != NULL)
            if(temp->next->val == temp->val)
                temp->next = temp->next->next;
            else
                temp=temp->next;
        return head;
    }
};