#include <iostream>
#include <vector>
using namespace std;

// Оголошення вузла зв'язаного списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Рекурсивна функція для подвоєння числа
int doubleListRecursive(ListNode* node) {
    if (!node) return 0; // Базовий випадок: досягли кінця списку

    // Рекурсивно обробляємо наступний вузол
    int carry = doubleListRecursive(node->next);

    // Поточне значення після множення на 2 плюс залишок
    int current = node->val * 2 + carry;

    // Оновлюємо поточний вузол
    node->val = current % 10;

    // Повертаємо залишок
    return current / 10;
}

// Функція для подвоєння числа у списку
ListNode* doubleList(ListNode* head) {
    int carry = doubleListRecursive(head);

    // Якщо залишився залишок, створюємо новий вузол спереду
    if (carry > 0) {
        ListNode* newHead = new ListNode(carry);
        newHead->next = head;
        return newHead;
    }
    return head;
}

// Допоміжна функція для створення списку
ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = head;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

// Допоміжна функція для виводу списку
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Приклад використання
int main() {
    vector<int> input1 = { 1, 8, 9 };
    vector<int> input2 = { 9, 9, 9 };

    ListNode* list1 = createList(input1);
    ListNode* list2 = createList(input2);

    cout << "Input: ";
    printList(list1);
    ListNode* result1 = doubleList(list1);
    cout << "Output: ";
    printList(result1);

    cout << "Input: ";
    printList(list2);
    ListNode* result2 = doubleList(list2);
    cout << "Output: ";
    printList(result2);

    return 0;
}
