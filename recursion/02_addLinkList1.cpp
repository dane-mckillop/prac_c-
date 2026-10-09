/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long num1 = linkValue(l1);
        long num2 = linkValue(l2);
        long result = num1 + num2;

        if (result == 0) return new ListNode(0, nullptr);
        return resultListNode(result);
    }

private:
    long linkValue(ListNode* node) {
        // Dereference: p->val == (*p).val
        if (!node) return 0;
        return node->val + 10 * linkValue((*node).next);
    }

    ListNode* resultListNode(long result) {
        if (result <= 0) return nullptr;
        return new ListNode(result % 10, resultListNode(result / 10));
    }
};