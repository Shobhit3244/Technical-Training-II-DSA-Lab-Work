#include "TT_Exp_3_Flattening_Mlutilevel_Doubly_Linked_List.h"
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int x) : val(x), prev(NULL), next(NULL), child(NULL) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* cur = head;
        while (cur) {
            if (cur->child) {
                Node* tail = flatten(cur->child);
                cur->child = nullptr;

                Node* next = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;

                tail->next = next;
                if (next) next->prev = tail;
            }
            cur = cur->next;
        }

        return head;
    }

    void printList(Node* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a sample multilevel doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->next = new Node(10);

    head->next->next->child->next->next->next->child = new Node(11);
    head->next->next->child->next->next->next->child->next = new Node(12);

    Solution solution;
    solution.flatten(head);
    solution.printList(head);

    return 0;
}
