// Name: Jingjing Pan
// lc link: https://leetcode.com/problems/insertion-sort-list/description/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* create_node(int val){
    struct ListNode* new_node = malloc(sizeof(struct ListNode));
    if(!new_node){
        printf("Malloc allocation failed.\n");
        return NULL;
    }

    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode* sentinel = malloc(sizeof(struct ListNode));
    if(!sentinel){
        printf("Malloc allocation failed.\n");
        return NULL;
    }

    sentinel->next = NULL; 
    struct ListNode* curr = head;

    while(curr){
        struct ListNode* prev = sentinel;

        while(prev->next && prev->next->val <= curr->val){
            prev = prev->next;
        }

        struct ListNode* temp = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = temp;
    }

    struct ListNode* sorted_head = sentinel->next;
    free(sentinel);

    return sorted_head;
}

void print_list(struct ListNode* head){
    while(head){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(struct ListNode* head){
    while(head){
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) /sizeof(arr[0]);

    struct ListNode* head = create_node(arr[0]);
    struct ListNode* temp = head;

    for(int i = 1; i < n; i++){
        temp->next = create_node(arr[i]);
        temp = temp->next;
    }
    printf("Before sorting: ");
    print_list(head);

    head = insertionSortList(head);
    printf("After sorting: ");
    print_list(head);

    free_list(head);
    return 0;

}


