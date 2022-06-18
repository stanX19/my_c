list *new_node (tree *node){
    list *new = malloc(sizeof(list));
    new->next = 0;
    new->t = node;
    return new;
}

void push(list **node, tree *t){
    list *new = new_node(t);
    new->next = *node;
    *node = new;
}

void pop(list **node){
    list *first = *node;
    if ((*node)->next)
        *node = (*node)->next;
    else
        *node = 0;
    free(first);
}

void get_elem(int *arr, tree *root, int*returnSize){
    list *previous = 0;
    tree *current = root;
    while (current){
        while (current){
            arr[(*returnSize)++] = current->val;
            push(&previous, current);
            current = current->left;
        }
        while (!current && previous) {
            current = previous->t->right;
            pop(&previous);
        }
    }
}