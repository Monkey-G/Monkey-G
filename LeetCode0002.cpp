/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution01 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr,*tail = nullptr;//head用于保存链表头返回结果，tail用于追踪扩充链表
        int carry = 0;
        while (l1 || l2){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1+n2+carry;
            carry = sum/10;

            if (!head)
            head = tail = new ListNode(sum%10);
            
            else{
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }

            if (l1)
            l1 = l1->next;
            
            if (l2)l2 = l2->next;
        }
    if (carry)
    tail->next = new ListNode(carry);
    return head;
    }
};