#include <iostream>
using namespace std;

// Структура для вузла списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycleHelper(ListNode* head, ListNode* slow, ListNode* fast) {
    if (!head || !head->next) return false; // Якщо список порожній або має один елемент

    if (slow == fast) return true; // Якщо зустрілися повільний і швидкий покажчики, є цикл

    // Рекурсивно рухаємося вперед
    return hasCycleHelper(head->next, slow->next, (fast->next ? fast->next->next : nullptr));
}

bool hasCycle(ListNode* head) {
    return hasCycleHelper(head, head, head);
}

int main() {
    // Приклад 1
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next; // Створюємо цикл
    cout << boolalpha << hasCycle(head1) << endl; // Очікується true

    // Приклад 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2; // Створюємо цикл
    cout << boolalpha << hasCycle(head2) << endl; // Очікується true

    // Приклад 3
    ListNode* head3 = new ListNode(1);
    cout << boolalpha << hasCycle(head3) << endl; // Очікується false

    return 0;
}
