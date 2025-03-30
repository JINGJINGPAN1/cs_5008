// Name: Jingjing Pan
// lc link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    int key;
    int value;
} HashMap;

int findIndex(HashMap* map, int mapSize, int key){
    for (int i = 0; i < mapSize; i++) {
        if (map[i].key == key) {
            return map[i].value;
        }
    }
    return -1; 
}

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) return NULL;
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* buildTreeHelper(int* preorder, int* inorder, HashMap* map, int* rootIndex, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int rootValue = preorder[*rootIndex];
    struct TreeNode* root = createNode(rootValue);
    (*rootIndex)++;

    int inorderIndex = findIndex(map, right + 1, rootValue);

    root->left = buildTreeHelper(preorder, inorder, map, rootIndex, left, inorderIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, map, rootIndex, inorderIndex + 1, right);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    HashMap* map = (HashMap*)malloc(inorderSize * sizeof(HashMap));
    for (int i = 0; i < inorderSize; i++) {
        map[i].key = inorder[i];
        map[i].value = i;
    }

    int rootIndex = 0;
    struct TreeNode* root = buildTreeHelper(preorder, inorder, map, &rootIndex, 0, preorderSize - 1);

    free(map);  
    return root;

}

void preorder_traverse(struct TreeNode* root){
    if(!root){
        return;
    }
   
    printf("%d, ", root->val);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

void inorder_traverse(struct TreeNode* root){
    if(!root){
        return;
    }
    inorder_traverse(root->left);
    printf("%d, ", root->val);
    inorder_traverse(root->right);
}

void postorder_traverse(struct TreeNode* root){
    if(!root){
        return;
    }
    postorder_traverse(root->left);
    postorder_traverse(root->right);
    printf("%d, ", root->val);
}


int main(){

    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};
    int preorderSize = sizeof(preorder) / sizeof(preorder[0]);
    int inorderSize = sizeof(inorder)/sizeof(inorder[0]);
    struct TreeNode* root = buildTree(preorder, preorderSize, inorder, inorderSize);
    printf("preorder: ");
    preorder_traverse(root);
    printf("\n");

    printf("inorder: ");
    inorder_traverse(root);
    printf("\n");

    printf("postorder: ");
    postorder_traverse(root);
    printf("\n");

    return 0;
}