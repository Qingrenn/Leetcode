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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)   return head;
        ListNode* even_head = new ListNode();
        ListNode* even_tail = even_head;

        ListNode* odd_iter = head;
        ListNode* even_iter;
        while (odd_iter != nullptr && odd_iter->next != nullptr) 
        {
            even_iter = odd_iter->next;
            odd_iter->next = even_iter->next;
            odd_iter = odd_iter->next;

            even_iter->next = even_tail->next;
            even_tail->next = even_iter;
            even_tail = even_iter;
        }

        even_iter = even_head->next;
        odd_iter = head;
        while (even_iter != nullptr) {
            ListNode* odd_tmp = odd_iter->next;
            odd_iter->next = even_iter->next;
            even_iter->next = odd_iter;
            
            even_iter = odd_iter->next;
            if (even_iter == nullptr && odd_tmp != nullptr){
                odd_iter->next = odd_tmp;
                break;
            }
            odd_iter = odd_tmp;
        }

        return even_head->next;
    }
};

/*
1.把链表拆成奇偶链表再合并（并不是最优解）
2.递归
3.迭代
*/