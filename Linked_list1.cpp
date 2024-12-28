#include <iostream>

using namespace std;

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Рекурсивна функція для об'єднання двох списків
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Якщо один зі списків порожній, повертаємо інший
    if (!list1) return list2;
    if (!list2) return list1;

    // Рекурсивно вибираємо менший елемент
    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

// Функція для друку списку
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Приклад 1
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* mergedList = mergeTwoLists(list1, list2);
    printList(mergedList);

    // Приклад 2
    list1 = nullptr;
    list2 = nullptr;
    mergedList = mergeTwoLists(list1, list2);
    printList(mergedList);

    // Приклад 3
    list1 = nullptr;
    list2 = new ListNode(0);
    mergedList = mergeTwoLists(list1, list2);
    printList(mergedList);

    return 0;
}