#include <iostream>
using namespace std;

// Структура для вузла списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для перевпорядкування списку
ListNode* reorderList(ListNode* head) {
    if (!head || !head->next) return head;

    // Допоміжна рекурсивна функція для розбиття на дві частини
    ListNode* slow = head;
    ListNode* fast = head;

    // Знаходимо середину списку
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Розбиваємо список на дві частини
    ListNode* secondHalf = slow->next;
    slow->next = nullptr;

    // Реверсуємо другу половину списку
    ListNode* prev = nullptr;
    while (secondHalf) {
        ListNode* next = secondHalf->next;
        secondHalf->next = prev;
        prev = secondHalf;
        secondHalf = next;
    }
    secondHalf = prev;

    // З’єднуємо першу і другу половину списку
    ListNode* firstHalf = head;
    while (secondHalf) {
        ListNode* temp1 = firstHalf->next;
        ListNode* temp2 = secondHalf->next;
        firstHalf->next = secondHalf;
        secondHalf->next = temp1;
        firstHalf = temp1;
        secondHalf = temp2;
    }

    return head;
}

// Функція для виведення списку
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Функція для створення списку
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

int main() {
    // Приклад 1: [1, 2, 3, 4]
    int arr1[] = { 1, 2, 3, 4 };
    ListNode* head1 = createList(arr1, 4);
    head1 = reorderList(head1);
    printList(head1);  // Виведе: 1 4 2 3

    // Приклад 2: [1, 2, 3, 4, 5]
    int arr2[] = { 1, 2, 3, 4, 5 };
    ListNode* head2 = createList(arr2, 5);
    head2 = reorderList(head2);
    printList(head2);  // Виведе: 1 5 2 4 3

    return 0;
}

