#include <string.h>
#include <stdlib.h>

typedef struct s_node {
    char *str;
    struct s_node *next;
} node;

node *new_node(char *str, int len){
    node *new = malloc(sizeof(node));
    new->str = malloc(len + 1);
    strcpy(new->str, str);
    new->next = 0;
    return new;
}

void push_node(node **root, char *str, int len){
    node *new = new_node(str, len);
    new->next = *root;
    *root = new;
}

void deallocate(node *root){
    if (root->next)
        deallocate(root->next);
    free(root->str);
    free(root);
}

int list_size(node *root){
    if (!root)
        return 0;
    return (1 + list_size(root->next));
}

int contains(node *root, char *str){
    if (!root)
        return 0;
    if (strcmp(root->str, str) == 0)
        return 1;
    return contains(root->next, str);
}

int numUniqueEmails(char ** emails, int emailsSize){
    int     addc;
    int     idx;
    int     rawc;
    int     ret;
    char    *rawstr;
    char    address[101];
    node    *list;
    
    list = 0;
    idx = 0;
    while (idx < emailsSize){
        rawc = 0;
        addc = 0;
        rawstr = emails[idx];
        while (rawstr[rawc] && rawstr[rawc] != '+' && rawstr[rawc] != '@'){
            if (rawstr[rawc] != '.')
                address[addc++] = rawstr[rawc];
            rawc++;
        }
        while (rawstr[rawc] && rawstr[rawc] != '@'){
            rawc++;
        }
        while (rawstr[rawc]){
            address[addc++] = rawstr[rawc];
            rawc++;
        }
        address[addc] = 0;
        if (!contains(list, address))
            push_node(&list, address, addc);
        idx++;
    }
    ret = list_size(list);
    deallocate(list);
    return (ret);
}

#include <stdio.h>

int main()
{
    char **emails = malloc(3 * 8);
    //["test.email+alex@leetcode.com", "test.email@leetcode.com"]
    emails[0] = "test.email+alex@leetcode.com";
    emails[1] = "test.email@leetcode.com";
    emails[2] = "testemail+david@lee.tcode.com";
    printf("%i$", numUniqueEmails(emails, 3));
    free(emails);
    return 0;
}