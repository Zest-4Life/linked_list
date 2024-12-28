#include <iostream>
#include <vector>
using namespace std;

// Структура для вузла зв'язаного списку
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для злиття двох зв'язаних списків
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Рекурсивна функція для злиття всіх списків
ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
    if (left > right) return nullptr;
    if (left == right) return lists[left];

    int mid = left + (right - left) / 2;
    ListNode* l1 = mergeKLists(lists, left, mid);
    ListNode* l2 = mergeKLists(lists, mid + 1, right);
    return mergeTwoLists(l1, l2);
}

// Головна функція
ListNode* mergeKLists(vector<ListNode*>& lists) {
    return mergeKLists(lists, 0, lists.size() - 1);
}

// Допоміжна функція для створення зв'язаного списку з вектора
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Допоміжна функція для виведення зв'язаного списку
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
    vector<vector<int>> input = { {1, 4, 5}, {1, 3, 4}, {2, 6} };
    vector<ListNode*> lists;
    for (const auto& vec : input) {
        lists.push_back(createList(vec));
    }

    ListNode* result = mergeKLists(lists);
    printList(result);

    return 0;
}
