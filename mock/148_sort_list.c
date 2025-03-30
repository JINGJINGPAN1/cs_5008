// Name: Jingjing Pan
// lc link: https://leetcode.com/problems/sort-list/description/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* create_node(int val) {
    struct ListNode* new_node = malloc(sizeof(struct ListNode));
    if (!new_node) {
        printf("Malloc allocation failed.\n");
        return NULL;
    }
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

struct ListNode* get_middle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct ListNode* merge_2_lists(struct ListNode* node1, struct ListNode* node2) {
    struct ListNode* sentinel = malloc(sizeof(struct ListNode));
    struct ListNode* p = sentinel;

    while (node1 && node2) {
        if (node1->val < node2->val) {
            p->next = node1;
            node1 = node1->next;
        } else {
            p->next = node2;
            node2 = node2->next;
        }
        p = p->next;
    }

    if (node1) {
        p->next = node1;
    }
    if (node2) {
        p->next = node2;
    }

    struct ListNode* sorted = sentinel->next;
    free(sentinel);
    return sorted;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* mid = get_middle(head);
    struct ListNode* l = head;
    struct ListNode* r = mid->next;
    mid->next = NULL;

    l = sortList(l);
    r = sortList(r);

    return merge_2_lists(l, r);
}

void print_list(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct ListNode* head = create_node(arr[0]);
    struct ListNode* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = create_node(arr[i]);
        temp = temp->next;
    }

    printf("Before sorting: ");
    print_list(head);

    head = sortList(head);

    printf("After sorting: ");
    print_list(head);

    free_list(head);

    return 0;
}
