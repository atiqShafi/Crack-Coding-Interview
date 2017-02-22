//�Ƴ������и���val�Ľڵ�
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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head!=NULL && head->val == val) //�Ƴ���һ��
            head = head->next;
        
        if(head != NULL)
        {
            ListNode *prev = head;
            ListNode *p = head->next;
            while(p!=NULL)
            {
                if(p->val == val) 
                    prev->next = p->next;
                else
                    prev = p;
                p = p->next;
            }
        }
        
        return head;
    }
};