#include "iostream"


using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() {
        next = nullptr;
        this->val = 0;
    }

    explicit ListNode(int val) {
        this->val = val;
        next = nullptr;
    }

    static void Insert(int val, ListNode *head) {
        if (head == nullptr) {
            return;
        }
        ListNode *cursor;
        auto new_node = new ListNode(val);
        for(cursor = head; cursor->next != nullptr; cursor = cursor->next) {
            // pass
        }
        cursor->next = new_node;
    }

    static void Print(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        ListNode* cursor;
        for(cursor = head; cursor->next != nullptr; cursor = cursor->next) {
            cout << cursor->next->val << endl;
        }
    }

    static ListNode* Reverse(ListNode *head) { // this head is head->next
        if(head == nullptr) {
            return head;
        }
        if(head->next == nullptr) {
            return head;
        }
        // nullptr->1->2->3->4->5->6->nullptr
        // nullptr<-1->2..->nullptr
        // nullptr<-1<-2<-3...<-6 return 6

        auto* new_tail = new ListNode();
        new_tail->next = head;
        ListNode* p2 = head;
        ListNode* p1 = new_tail;
        while(true) {
            if(p2 == nullptr) {
                head->next = nullptr;
                return p1;
            }
            auto t = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = t;
        }
    }
};

int main() {
    ListNode head;
    ListNode::Insert(1, &head);
    ListNode::Insert(2, &head);
    ListNode::Insert(3, &head);
    ListNode::Insert(4, &head);
    ListNode::Insert(5, &head);
    ListNode::Insert(6, &head);
    // ListNode::Print(&head);
    auto a = ListNode::Reverse(head.next);
    ListNode::Print(a);
}