#include <iostream>
using namespace std;

// Визначення структури вузла зв'язаного списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {}
};

// Рекурсивна функція для розділення списку
void partitionRecursive(ListNode* current, ListNode*& lessHead, ListNode*& lessTail, ListNode*& greaterHead, ListNode*& greaterTail, int x) {
    // Базовий випадок: кінець списку
    if (!current) return;

    // Обробка поточного вузла
    if (current->val < x) {
        if (!lessHead) {
            lessHead = current;
            lessTail = current;
        }
        else {
            lessTail->next = current;
            lessTail = current;
        }
    }
    else {
        if (!greaterHead) {
            greaterHead = current;
            greaterTail = current;
        }
        else {
            greaterTail->next = current;
            greaterTail = current;
        }
    }

    // Рекурсивний виклик для наступного вузла
    partitionRecursive(current->next, lessHead, lessTail, greaterHead, greaterTail, x);
}

// Основна функція для розділення списку
ListNode* partition(ListNode* head, int x) {
    if (!head) return nullptr; // Порожній список

    ListNode* lessHead = nullptr;
    ListNode* lessTail = nullptr;
    ListNode* greaterHead = nullptr;
    ListNode* greaterTail = nullptr;

    // Рекурсивне розділення
    partitionRecursive(head, lessHead, lessTail, greaterHead, greaterTail, x);

    // З'єднання двох списків
    if (lessTail) lessTail->next = greaterHead;
    if (greaterTail) greaterTail->next = nullptr;

    return lessHead ? lessHead : greaterHead; // Повертаємо голову нового списку
}

// Допоміжна функція для створення списку
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Допоміжна функція для друку списку
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Приклад 1
    int arr1[] = { 1, 4, 3, 2, 5, 2 };
    ListNode* head1 = createList(arr1, 6);
    int x1 = 3;

    cout << "Input: ";
    printList(head1);

    ListNode* result1 = partition(head1, x1);

    cout << "Output: ";
    printList(result1);

    // Приклад 2
    int arr2[] = { 2, 1 };
    ListNode* head2 = createList(arr2, 2);
    int x2 = 2;

    cout << "Input: ";
    printList(head2);

    ListNode* result2 = partition(head2, x2);

    cout << "Output: ";
    printList(result2);

    return 0;
}
