// class Solution {
// public:
//     bool hasCycle(ListNode* head) {
//         unordered_set<ListNode*> my_set;
//         while(head != nullptr) {
//             if(my_set.count(head)) {
//                 return true;
//             }
//             my_set.insert(head);
//             head = head->next;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode* head) {

        if(head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* s = head;
        ListNode* f = head->next;
        while(true) {
            if(s == f) {
                return true;
            }
            if(f == nullptr || f->next == nullptr) {
                return false;
            }
            s = s->next;
            f = f->next->next;
        }
    }
};


