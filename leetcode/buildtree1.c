#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


typedef struct TreeNode node;

void printPreorder(node* root)
{
    if (root == 0){
        printf("null, ");
        return;
    }
    printf("%i, ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}



node* new_node(int val)
{
    node *new = (node*)malloc(sizeof(node));
    new->val = val;
    new->left = 0;
    new->right = 0;
    return (new);
}

int find(int * arr, int len, int nb){
    for (int i = 0; i < len; i++){
        if (arr[i] == nb)
            return i;
    }
    return -1;
}

node *build_recur(int *in, int *pos, int inl, int inh, int *posh){
    int rootidx;
    
    if (inl >= inh)
        return 0;
    node *root = new_node(pos[(*posh)--]);
    rootidx = find(in, inh, root->val);
    
    root->left = build_recur(in, pos, inl, rootidx, posh);
    root->right = build_recur(in, pos, rootidx + 1, inh, posh);
    
    return root;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int posh = --postorderSize;
    return build_recur(inorder, postorder, 0, inorderSize, &posh);
}

int main()
{
    int inorder[] = {9,3,15,20,7}, postorder[] = {9,15,7,20,3};
    printPreorder(buildTree(inorder, 5, postorder, 5));
    
    printf("\nHello World");

    return 0;
}
