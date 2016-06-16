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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
			return NULL;
		else if(head->next==NULL)
			return head;

		ListNode * odd=new ListNode(0);
		ListNode * oddCur=new ListNode(0);
		ListNode * even=new ListNode(0);
		ListNode * evenCur=new ListNode(0);
		ListNode * tmp=head;

		oddCur=odd;
		evenCur=even;

		

		int count=1;

		while(tmp!=NULL)
		{
			if(count%2)
			{
				oddCur->next=new ListNode(tmp->val);
				oddCur=oddCur->next;
			}
			else
			{
				evenCur->next=new ListNode(tmp->val);
				evenCur=evenCur->next;
			}
			count++;
			tmp=tmp->next;
		}

        oddCur->next=even->next;
        return odd->next;
    }
};