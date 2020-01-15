/*
 * Reverse Nodes in K Groups
 * By Sam Firnhaber
 */

Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    void swapNodes(ListNode* head, int index1, int index2) {
        if (index1 == index2)
            return;
        ListNode* node1;
        for (int i = 0; i < index2; i++) {
            if (i == index1)
                node1 = head;
            head = head->next;
        }
        int temp = node1->val;
        node1->val = head->val;
        head->val = temp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length;
        ListNode* ptr = head;
        for (length = 0; ptr != NULL; length++)
            ptr = ptr->next;
        if (length % 2 == 1 && k % 2 == 0)
            length--;
        int h = 0;
        for (int i = 0; i < length / k; i++) {
            int l = 0;
            for (int j = h; j < k/2 + h; j++) {
                l++;
                swapNodes(head, j, h + k - l);
            }
            h += k;
        }
        return head;
    }
};