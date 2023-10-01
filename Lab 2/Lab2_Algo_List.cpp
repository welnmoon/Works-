#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    MyLinkedList();
    ~MyLinkedList();
    size_t get_size(); // Получить размер списка
    void add_at_tail(int val); // Добавить элемент в конец списка
    void add_at_head(int val); // Добавить элемент в начало списка
    void add_at_index(size_t index, int val); // Добавить элемент по индексу
    void delete_at_index(size_t index);
    void print();
    void reverse();
private:
    ListNode* head;
    size_t size = 0;
};

MyLinkedList::MyLinkedList() : head(nullptr), size(0) {}

MyLinkedList::~MyLinkedList()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Вызван деструктор, прощайте!";
    ListNode* curr = head;
    while (curr != nullptr)
    {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}


size_t MyLinkedList::get_size() { return size; }

void MyLinkedList::add_at_tail(int val) {
    ++size;
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
    }
}

void MyLinkedList::add_at_index(size_t index, int val) {
    if (index < 0 || index > size) {
        std::cerr << "Index is out of bounds of the list. "
            << "Current size: " << size << "\n";
        return;
    }

    ++size; // Не смог выяснить ошибку, размер при выводе 7 а не 6 ( должно быть 6 ). Проблема в этом методе
    ListNode* newNode = new ListNode(val);

    if (index == 0) {
        add_at_head(val);
        return;
    }

    ListNode* prev = head;
    ListNode* curr = head->next;
    size_t pos = 0;

    while (pos < index - 1) {
        prev = prev->next;
        curr = curr->next;
        ++pos;
    }

    newNode->next = curr;
    prev->next = newNode;
}


void MyLinkedList::delete_at_index(size_t index) {
    if (index >= size) {
        std::cerr << "Index is out of bounds of the list. "
            "Current size: " << size << "\n";
        return;
    }
    --size;

    ListNode* prev = head;

    if (index == 0) {
        head = head->next;
        delete prev;
    }

    ListNode* curr = head->next;
    size_t pos = 0;

    while (prev != nullptr && pos < index - 1) {
        prev = prev->next;
        curr = curr->next;
        ++pos;
    }
    prev->next = curr->next;
    delete curr;
}

void MyLinkedList::add_at_head(int val) {
    ++size;
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void MyLinkedList::print() {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << "\t";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void MyLinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    MyLinkedList* obj = new MyLinkedList();
    for (int val : arr) {
        obj->add_at_tail(val);
    }

    std::cout << "First List:\n";
    obj->print();
    std::cout << "Size of new list: " << obj->get_size() << std::endl;

    std::cout << "Adding 66 at index 0:\n";
    obj->add_at_index(0, 66);
    obj->print();
    std::cout << "Size of new list: " << obj->get_size() << std::endl;

    std::cout << "Deleting at index 3:\n";
    obj->delete_at_index(3);
    obj->print();
    std::cout << "Size of new list: " << obj->get_size() << std::endl;

    std::cout << "Adding 55 at head:\n";
    obj->add_at_head(55);
    obj->print();
    std::cout << "Size of new list: " << obj->get_size() << std::endl;

    std::cout << "Reversing the list:\n";
    obj->reverse();
    obj->print();

    std::cout << "Size of new list: " << obj->get_size() << std::endl;

    return 0;
}
