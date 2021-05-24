//
//#include "iostream"
//#include "memory"
//
//using namespace std;
//class ListNode {
//public:
//    int val{};
//    shared_ptr<ListNode> next;
//    ListNode() = default;
//    explicit ListNode(int val) {
//        this->val = val;
//        next = nullptr;
//    }
//};
//
//void Insert(int val, shared_ptr<ListNode> &head) {
//
//    shared_ptr<ListNode> temp = head;
//    for (; temp->next != nullptr; temp = temp->next) {
//        // do nothing
//    }
//    auto *new_node = new ListNode();
//    new_node->val = val;
//    new_node->next = nullptr;
//    temp->next = shared_ptr<ListNode>(new_node);
//}
//
//void Print(shared_ptr<ListNode> &head) {
//    if(head == nullptr) {
//        cout << "fuck" << endl;
//        return;
//    }
//    shared_ptr<ListNode> temp = head->next;
//    if(temp == nullptr) {
//        cout << "bitch" << endl;
//        return;
//    }
//    for(; temp != nullptr; temp = temp->next) {
//        cout << temp->val << endl;
//    }
//}
//class Solution {
//public:
//    static shared_ptr<ListNode> addTwoNumbers(shared_ptr<ListNode> l1, shared_ptr<ListNode> l2) {
//        shared_ptr<ListNode> result = shared_ptr<ListNode>(new ListNode(-1));
//        shared_ptr<ListNode> temp = result;
//        bool carry = false;
//        while (l1 != nullptr || l2 != nullptr) {
//            int sum = 0;
//            if(l1 != nullptr) {
//                sum += l1->val;
//                l1 = l1->next;
//            }
//            if(l2 != nullptr) {
//                sum += l2->val;
//                l2 = l2->next;
//            }
//            if(carry) {
//                sum++;
//                temp->next = shared_ptr<ListNode>(new ListNode(sum % 10));
//                temp = temp->next;
//                if(sum >= 10) {
//                    carry = true;
//                } else {
//                    carry = false;
//                }
//            } else {
//                temp->next = shared_ptr<ListNode>(new ListNode(sum % 10));
//                // 多出来一个0
//                temp = temp->next;
//                if(sum >= 10) {
//                    carry = true;
//                } else {
//                    carry = false;
//                }
//            }
//        }
//        if(carry) {
//            temp->next = shared_ptr<ListNode>(new ListNode(1));
//        }
//        return result->next;
//    }
//};
//int main() {
//    auto head = shared_ptr<ListNode>(new ListNode());
//    Insert(9, head);
//    Insert(2, head);
//    Insert(8, head);
//    Insert(4, head);
//    auto head1 = shared_ptr<ListNode>(new ListNode());
//    Insert(9, head1);
//    Insert(2, head1);
//    Insert(8, head1);
//    Insert(4, head1);
//    auto result = Solution::addTwoNumbers(head, head1);
//    Print(result);
//}



#include "iostream"

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void Insert(int val, ListNode *head) {
        if (head == nullptr) {
            cout << "empty head" << endl;
            return;
        }
        ListNode *i = head;
        while (true) {
            if (i->next != nullptr) {
                i = i->next;
            } else {
                break;
            }
        }

        ListNode *node = new ListNode(val);
        i->next = node;
    }

public:
    void Print(ListNode *head) {
        if (head == nullptr) {
            cout << "empty head" << endl;
            return;
        }
        if (head->next == nullptr) {
            cout << "no value" << endl;
            return;
        }
        ListNode *temp = head->next;
        for (; temp != nullptr; temp = temp->next) {
            cout << temp->val << endl;
        }
        return;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        bool carry = false;
        ListNode *output = new ListNode(-1, nullptr);
        ListNode *temp = output;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;
            if (l1 != nullptr) {
                cout << "l1 moves to " << l1->val << endl;
                sum += l1->val;
                l1 = l1->next;
                cout << "sum is " << sum << endl;
            }
            if (l2 != nullptr) {
                cout << "l2 moves to " << l2->val << endl;
                sum += l2->val;
                l2 = l2->next;
                cout << "sum is " << sum << endl;
            }
            if (carry) {
                sum += 1;
            } else {
                // pass
            }
            if (sum >= 10) {
                carry = true;
            } else {
                carry = false;
            }
            ListNode *new_node = new ListNode(sum % 10, nullptr);
            temp->next = new_node;
            temp = temp->next;
        }
        if (carry) {
            ListNode *new_node = new ListNode(1, nullptr);
            temp->next = new_node;
        }
        return output;
    }
};

int main() {
    Solution s = Solution();
    ListNode head = ListNode(-1, nullptr);
    s.Insert(2, &head);
    s.Insert(9, &head);
    s.Insert(3, &head);
    s.Insert(8, &head);
    s.Insert(9, &head);
    ListNode head1 = ListNode(-1, nullptr);
    s.Insert(2, &head1);
    s.Insert(9, &head1);
    s.Insert(3, &head1);
    s.Insert(8, &head1);
    s.Insert(9, &head1);
    auto a = s.addTwoNumbers(head.next, head1.next);
    s.Print(a);
}

