#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode tree;

typedef struct s_list {
    int len;
    int val;
    struct s_list *next;
} node;

typedef struct s_linked {
    int len;
    node *first_node;
    struct s_linked *next;
} base_list;

//tree functions
tree *new_tree(int val){
    tree *new = malloc(sizeof(tree));
    new->val = val;
    new->left = 0;
    new->right = 0;
    return new;
}

//linked list functions

node *new_node(int val){
    node *new = malloc(sizeof(node));
    new->len = 1;
    new->val = val;
    new->next = 0;
    return new;
}

void push_node(node **start, int val){
    node *new = malloc(sizeof(node));
    if (*start)
        new->len = (*start)->len + 1;
    else
        new->len = 1;
    new->val = val;
    new->next = *start;
    *start = new;
}

void push_all_base(base_list *start, int val){
    while (start){
        push_node(&(start->first_node), val);
        start = start->next;
    }
}

base_list *new_base_list(int val){
    base_list *new = malloc(sizeof(base_list));
    new->first_node = new_node(val);
    new->len = 1;
    new->next = 0;
    return new;
}

base_list *cat_base_list(base_list *dest, base_list *src){
    if (!dest)
        return src;
    base_list *current = dest;
    while (current->next){
        current = current->next;
    }
    if (src){
        dest->len += src->len;
        current->next = src;
    }
    return dest;
}

void free_node(node *first){
    if (first->next)
        free_node(first->next);
    free(first);
}

void free_base_list(base_list *first){
    if (first->next)
        free_base_list(first->next);
    free_node(first->first_node);
    free(first);
}

// linked list to array
int **list_to_arr(base_list *root, int* returnSize, int** returnColumnSizes){
    int **final = malloc(sizeof(int*) * root->len);
    base_list *current_base = root;
    node *current_node;
    int i;
    int b_idx = 0;
    
    *returnColumnSizes = malloc(sizeof(int) * root->len);
    *returnSize = root->len;
    
    while (current_base){
        current_node = current_base->first_node;
        final[b_idx] = malloc(sizeof(int) * current_node->len);
        (*returnColumnSizes)[b_idx] = current_node->len;
        
        i = 0;
        while (current_node){
            final[b_idx][i] = current_node->val;
            current_node = current_node->next;
            i++;
        }
        current_base = current_base->next;
        b_idx++;
    }
    return final;
}

// searching the tree
base_list *pathSum_recursion(tree *root, int current_sum, int targetSum){
    current_sum += root->val;
    base_list *result = 0;
    if (current_sum == targetSum && root->right == 0 && root->left == 0){
        return new_base_list(root->val);
    }
    if (root->left)
        result = pathSum_recursion(root->left, current_sum, targetSum);
    if (root->right){
        if (result)
            result = cat_base_list(pathSum_recursion(root->right, current_sum, targetSum), result);
        else
            result = pathSum_recursion(root->right, current_sum, targetSum);
    }
    if (result)
        push_all_base(result, root->val);
    
    return result;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    int **ret;
    base_list *result = 0;
    
    if (root)
        result = pathSum_recursion(root, 0, targetSum);
    if (result){
        ret = list_to_arr(result, returnSize, returnColumnSizes);
        free_base_list(result);
    }
    else {
        *returnColumnSizes = 0;
        *returnSize = 0;
        ret = 0;
    }
    
    return ret;
}

#include <stdio.h>
void deallocate (tree *node){
    if (!node)
        return;
    deallocate(node->left);
    deallocate(node->right);

    free (node);
}
int main()
{
    tree *root = new_tree(5);
    root->left = new_tree(4);
    root->right = new_tree(8);
    root->left->left = new_tree(11);
    root->left->left->right = new_tree(2);
    root->left->left->right->left = new_tree(0);
    root->left->left->left = new_tree(7);
    root->right->right = new_tree(4);
    root->right->left = new_tree(13);
    root->right->right->left = new_tree(5);
    root->right->right->right = new_tree(1);
    
    tree *root1 = 0;
    
    int returnSize;
    int* returnColumnSizes;
    int **array = pathSum(root, 22, &returnSize, &returnColumnSizes);
    for (int i  = 0; i < returnSize; i++){
        for (int n  = 0; n < returnColumnSizes[i]; n++)
            printf("%i, ", array[i][n]);
        free(array[i]);
        printf("\n");
    }
    free(array);
    free(returnColumnSizes);
    deallocate(root);
    deallocate(root1);
    printf("Hello World");

    return 0;
}
