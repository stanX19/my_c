#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
    int data;
    struct s_node *left;
    struct s_node *right;
    struct s_node *top;
    struct s_node *bot;
} node;

node *new_node(int value){
    node *new = malloc(sizeof(node));
    new->data = value;
    new->left = (void*)0;
    new->right = (void*)0;
    new->top = (void*)0;
    new->bot = (void*)0;
    return new;
}

node *append_right(node *begin_node, int value)
{
    node *last = begin_node;
    while (last->right)
        last = last->right;
    last->right = new_node(value);
    last->right->left = last;
    return last->right;
}

node *append_bot(node *begin_node, int value)
{
    node *last = begin_node;
    while (last->bot)
        last = last->bot;
    last->bot = new_node(value);
    last->bot->top = last;
    return last->bot;
}

void print_row(node *begin_node)
{
    while (begin_node){
        printf("%c", begin_node->data);
        begin_node = begin_node->right;
    }
}

void print_tab(node *origin)
{
    while (origin){
        print_row(origin);
        printf("\n");
        origin = origin->bot;
    }
}

void zip_rows(node *row1, node *row2)
{
    while (row1 && row2){
        row1->bot = row2;
        row2->top = row1;
        row1 = row1->right;
        row2 = row2->right;
    }
}

void free_all_node(node *current)
{
    int signature = -1;
    current->data = signature; // i am already reached and registered to be freed
    if (current->left  && current->left ->data != signature)   free_all_node(current->left);
    if (current->right && current->right->data != signature)   free_all_node(current->right);
    if (current->top   && current->top  ->data != signature)   free_all_node(current->top);
    if (current->bot   && current->bot  ->data != signature)   free_all_node(current->bot);
    if (current->left) current->left ->right = (void*)0; // register self as null;
    if (current->right)current->right->left = (void*)0;
    if (current->top)  current->top  ->bot = (void*)0;
    if (current->bot)  current->bot  ->top = (void*)0;
    free(current);
}

node *char_tab_to_node(char**strs)
{
    int y = 0, x = 0;
    node *origin = new_node(**strs);
    node *row = origin;
    while (strs[y]){
        row = append_bot(row, strs[y][x]);
        while(strs[y][++x])
            append_right(row, strs[y][x]);
        x = 0;
        y++;
    }
    origin = origin->bot;
    free(origin->top);
    origin->top = (void*)0;
    row = origin;
    while (row->bot){
        zip_rows(row, row->bot);
        row = row->bot;
    }
    return origin;
}

void spread(node *current, int target)
{
    int value = current->data;
    if (current->left  && current->left ->data == target){
        current->left ->data = value;
        spread(current->left , target);
    }
    if (current->right && current->right->data == target){
        current->right->data = value;
        spread(current->right, target);
    }
    if (current->top   && current->top  ->data == target){
        current->top  ->data = value;
        spread(current->top  , target);
    }
    if (current->bot   && current->bot  ->data == target){
        current->bot  ->data = value;
        spread(current->bot  , target);
    }
}