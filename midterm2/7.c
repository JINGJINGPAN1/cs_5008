// 7. Write a function called searchValue in C to determine if a given value exists in a Binary
// Search Tree.
// Hint: To search for a key in a binary search tree, start at the root. If the current node is
// NULL or matches the key, return the node. If the key is greater, move right; if smaller, move
// left. Repeat this process until the key is found or a NULL node is reached, indicating the key
// is absent.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int item){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* searchValue(struct Node* root, int value){
    // TO: Write your code here
    if(root == NULL){
        return root;
    }

    struct Node* curr = root;
    while(curr != NULL){
        if(value < curr->value){
            curr = curr->left;
        }else if(value > curr-> value){
            curr = curr->right;
        }else{
            return curr;
        }
    }

    return NULL;
}
int main()
{
    struct Node* root = createNode(25);
    root->left = createNode(15);
    root->right = createNode(50);
    root->left->left = createNode(10);
    root->left->right = createNode(20);
    root->right->left = createNode(35);
    root->right->right = createNode(75);
    printf(searchValue(root, 20) != NULL ? "Value 20 Found\n" : "Value 20 Not Found\n");
    printf(searchValue(root, 40) != NULL ? "Value 40 Found\n" : "Value 40 Not Found\n");
    return 0;
}