#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int x) {
        this->val = x;
        this->prev = this->next = nullptr;
    }
};

class MyLinkedList {
public:
    MyLinkedList() : head(nullptr) {}
    void insertNode(size_t index, int val);
    void add_at_tail(int val);
    void add_at_head(int val);
    void print();
private:
    ListNode* head;
};

void MyLinkedList::insertNode(size_t index, int val) {
    ListNode* newNode = new ListNode(val);

    if (index == 0) {
        add_at_head(val);
        return;
    }

    ListNode* curr = head;
    size_t pos = 0;

    while (curr != nullptr && pos < index - 1) {
        curr = curr->next;
        ++pos;
    }

    if (curr != nullptr) {
        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
    }
    else {
        add_at_tail(val);
    }
}

void MyLinkedList::add_at_head(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void MyLinkedList::add_at_tail(int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void MyLinkedList::print() {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << "\t";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    MyLinkedList obj;
    for (int val : arr) {
        obj.add_at_tail(val);
    }

    obj.insertNode(2, 6);
    obj.print();
    return 0;
}
