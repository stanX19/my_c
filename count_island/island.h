#ifndef ISLAND_H_H
#define ISLAND_H_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_node
{
	int data;
	struct s_node *left;
	struct s_node *right;
	struct s_node *top;
	struct s_node *bot;
} node;

node *new_node(int value);

node *append_right(node *begin_node, int value);

node *append_bot(node *begin_node, int value);

void print_row(node *begin_node);

void print_tab(node *origin);

void zip_rows(node *row1, node *row2);

void free_all_node(node *origin);

node *char_tab_to_node(char**strs);

void spread(node *current, int target);

int len(char *str);

void ft_strncpy(char *dest, char *src, int n);

char **ft_split(char *str);

void free_txt_tab(char**tab);

char *read_file(char * path);

#endif

