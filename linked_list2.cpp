#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Рекурсивна функція для видалення дублікатів
ListNode* removeDuplicates(ListNode* head) {
    // Базовий випадок: якщо список порожній або має тільки один елемент
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Якщо поточний елемент та наступний однакові
    if (head->val == head->next->val) {
        // Пропускаємо наступний елемент
        head->next = head->next->next;
        // Рекурсивно викликаємо функцію для наступного елемента
        return removeDuplicates(head);
    }

    // Якщо поточний елемент не дублюється, рекурсивно викликаємо для наступного елемента
    head->next = removeDuplicates(head->next);

    return head;
}

// Функція для друку списку
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Створення прикладу списку [1, 1, 2]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    // Видаляємо дублікати
    head = removeDuplicates(head);

    // Виводимо результат
    printList(head);  // Виведе: 1 2

    // Створення іншого прикладу списку [1, 1, 2, 3, 3]
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(3);

    // Видаляємо дублікати
    head2 = removeDuplicates(head2);

    // Виводимо результат
    printList(head2);  // Виведе: 1 2 3

    return 0;
}

