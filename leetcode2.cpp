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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
			return l2;
		else if(l2==NULL)
			return l1;
		
		int carry=0,val1=0,val2=0,tmp=0;
		ListNode *tail=new ListNode(0);
		ListNode *ptr=tail;
		while(l1!=NULL||l2!=NULL)
		{
			val1=0;
			if(l1!=NULL)
			{
				val1=l1->val;
				l1=l1->next;
			}
			val2=0;
			if(l2!=NULL)
			{
				val2=l2->val;
				l2=l2->next;
			}
			tmp=val1+val2+carry;
			ptr->next=new ListNode(tmp%10);
			carry=tmp/10;
			ptr=ptr->next;
		}
		if(carry==1)
		{
			ptr->next=new ListNode(1);
		}
		return tail->next;
    }
};