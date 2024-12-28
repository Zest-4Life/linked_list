#include <iostream>
using namespace std;

// Структура вузла списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Рекурсивна функція для видалення вузла
void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) return; // Перевірка на крайні випадки
    node->val = node->next->val; // Копіюємо значення наступного вузла в поточний вузол
    node->next = node->next->next; // Оновлюємо зв’язок, пропускаючи наступний вузол
}

// Функція для виведення списку
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Створення зв’язаного списку 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Виведення списку до видалення
    cout << "Before deletion: ";
    printList(head);

    // Вибір вузла для видалення (наприклад, вузол зі значенням 5)
    ListNode* nodeToDelete = head->next; // Це вузол з значенням 5

    // Видалення вузла
    deleteNode(nodeToDelete);

    // Виведення списку після видалення
    cout << "After deletion: ";
    printList(head);

    return 0;
}
