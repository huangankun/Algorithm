void Reverse_LinkList(LinkList* head)
{
	if((head == NULL) || (head->next == NULL))
            return head;
	LinkList* p,q,temp;
	p = head;
	q =NULL;
	temp=NULL;
	while(p!=NULL)
	{
		temp=p->next;
		p->next=q;
		q=p;
		p=temp;
	}
	return q;
}

LINK_NODE *ReverseLink2(LINK_NODE *head)
{
        LINK_NODE *newHead;
    
        if((head == NULL) || (head->next == NULL))
            return head;
    
        newHead = ReverseLink2(head->next); /*�ݹ鲿��*/
        head->next->next = head; /*��˷����*/
        head->next = NULL;
    
        return newHead;
 }