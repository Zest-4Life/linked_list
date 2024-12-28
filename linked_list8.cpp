#include <iostream>
#include <vector>
using namespace std;

// Визначення структури вузла пов'язаного списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для реверсу k вузлів
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) return nullptr;

    // Перевірка, чи залишилося достатньо вузлів для реверсу
    ListNode* temp = head;
    for (int i = 0; i < k; ++i) {
        if (!temp) return head;
        temp = temp->next;
    }

    // Реверс першої групи з k вузлів
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    for (int i = 0; i < k; ++i) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Рекурсивний виклик для наступних груп
    head->next = reverseKGroup(next, k);

    return prev;
}

// Функція для створення списку з вектора
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Функція для виведення списку
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Приклад 1
    vector<int> values1 = { 1, 2, 3, 4, 5 };
    int k1 = 2;
    ListNode* head1 = createList(values1);
    cout << "Input: ";
    printList(head1);
    ListNode* result1 = reverseKGroup(head1, k1);
    cout << "Output: ";
    printList(result1);

    // Приклад 2
    vector<int> values2 = { 1, 2, 3, 4, 5 };
    int k2 = 3;
    ListNode* head2 = createList(values2);
    cout << "Input: ";
    printList(head2);
    ListNode* result2 = reverseKGroup(head2, k2);
    cout << "Output: ";
    printList(result2);

    return 0;
}