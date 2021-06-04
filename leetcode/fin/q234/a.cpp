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
    static ListNode *Reserve(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;

        }
        ListNode *new_tail = new ListNode();
        new_tail->next = head;
        ListNode *my_copy = new_tail->next;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (true) {
            if (p2 == nullptr) {
                my_copy->next = nullptr;
                cout << p1->val << endl;               
                return p1;
            }
            ListNode *temp = p2->next;
            p2->next = p1;
            p1 = p2;
            // p1 = p1->next
            p2 = temp;
        }
    }

    static bool isPalindrome(ListNode *head) {
        bool flag = true;
        ListNode *counterCursor;
        int len = 0;
        for (counterCursor = head; counterCursor != nullptr; counterCursor = counterCursor->next) {
            len++;
        }
        int half_len = floor(len / 2);
        ListNode *new_cursor = head;
        if (len / 2 != half_len) {
            // odd
            for (int i = 0; i <= half_len; i++) {
                new_cursor = new_cursor->next;
            }
        } else {
            // even
            for (int i = 0; i <= half_len - 1; i++) {
                new_cursor = new_cursor->next;
            }
        }
        ListNode *reserve_node = Reserve(new_cursor);
        ListNode *index = reserve_node;
        ListNode *new_head = head;
        for (; index != nullptr; index = index->next, new_head = new_head->next) {
            if(new_head->val == index->val) {
                // pass
            } else {
                return !flag;
            }
        }
        return flag;
    }
};
