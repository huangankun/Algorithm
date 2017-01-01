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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head ==NULL || head->next==NULL) return head;
        ListNode *helper=new ListNode(0);
        ListNode *ret=head;
        ListNode *cur=helper;
        while(ret && ret->next){
            ListNode *next=ret->next->next;
            cur->next = ret->next;
            cur=cur->next;
            cur->next=ret;
            cur=cur->next;
            cur->next=NULL;
            ret=next;
        }
        if(ret) cur->next=ret;
        return helper->next;
    }
};