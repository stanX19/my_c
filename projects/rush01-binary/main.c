#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int hash[1024];
int g_n;

typedef struct s_node
{
    int data;
    int argv[2];
    struct s_node *left;
    struct s_node *right;
    struct s_node *top;
    struct s_node *bot;
} node;

node *new_node(int value){
    node *new = malloc(sizeof(node));
    new->argv[0] = 0;
    new->argv[1] = 0;
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
        printf("%i ", hash[begin_node->data]);
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

void assign_argv(node *origin, int *argv)
{
    int idx = 0;
    node *cur = origin;
    while (idx < g_n){
        cur->argv[1] = argv[idx++];
        if (idx < g_n)
            cur = cur->right;
    }
    idx = 3 * g_n;
    while (cur){
        cur->argv[0] = argv[idx++];
        cur = cur->bot;
    }
    cur = origin;
    idx = 2 * g_n;
    while (idx < 3 * g_n){
        cur->argv[0] = argv[idx++];
        if (idx < 3 * g_n)
            cur = cur->bot;
    }
    idx = g_n;
    while (cur){
        cur->argv[1] = argv[idx++];
        cur = cur->right;
    }
}

node *tab_init(int len)
{
    int x;
    int y = 0;
    node *origin = new_node(511);
    node *row = origin;
    while (y < len){
        x = 0;
        while (++x < len){
            append_right(row, 511);
        }
        y+=1;
        if (y < len)
            row = append_bot(row, 511);
    }
    row = origin;
    while (row->bot){
        zip_rows(row, row->bot);
        row = row->bot;
    }
    return origin;
}

int ft_pow(int nb, int power){
    if (power > 0)
        return (nb * ft_pow(nb, power - 1));
    return 1;
}

void hash_init(void){
    memset(hash, 0, 1024 * sizeof(int));
    for (int i = 0; i < 9; i++)
        hash[ft_pow(2, i)] = i + 1;
}

void	write_nb(int nb)
{
	char	c;

	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb > 9)
		write_nb(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}


int	is_valid(node*row, node*cur)
{
    (void)row;
    (void)cur;
    return 1;
}

void constrain(node* row, int val)
{
    node* col = row->bot;
    while (col){
        if (col->data & val)
            col->data -= val;
        col = col->bot;
    }
    row = row->right;
    while (row){
        if (row->data & val)
            row->data -= val;
        row = row->right;
    }
}

void undo_constrain(node* row, int val)
{
    node* col = row->bot;
    while (col){
        col->data |= val;
        col = col->bot;
    }
    row = row->right;
    while (row){
        row->data |= val;
        row = row->right;
    }
}

int	solve(node* origin, node *row, node *cur)
{
    int val = 1;
    int temp;
    
    //print_tab(origin);
    //printf("val = %i\n", origin->right->right->right->right->right->right->right->right->bot->data);
    //sleep(1);
	if (!cur){
	    if (!row->bot)
	        return (1);
	    row = row->bot;
	    cur = row;
	}
	if (hash[cur->data]){ // collapsed to one
	    constrain(cur, cur->data);
	    if (solve(origin, row, cur->right))
	        return 1;
        else
            undo_constrain(cur, cur->data);
        return 0;
	}
	while (val < cur->data){
	    if (val & cur->data){ //is a possible number
	        temp = cur->data;
	        cur->data = val;
	        constrain(cur, val);
	        if (solve(origin, row, cur->right))
	            return 1;
	        undo_constrain(cur, val);
	        cur->data = temp;
	    }
        val *= 2;
	}
	return (0);
}

int	*split_to_i(char *str)
{
	int	*result;
	int	i;
	int	len;

	i = 0;
	len = 0;
	result = malloc(100 * sizeof(int));
	memset(result, 0, 100 * sizeof(int));
	while (str[i])
	{
		if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == ' ')
			&& str[i] <= '9' && str[i] >= '0')
			result[len++] = str[i] - '0';
		else if (str[i] <= '9' && str[i] >= '0')
			result[len - 1] = ((result[len - 1] * 10 + str[i]) - '0');
		i++;
	}
	return (result);
}

int	main(int argc, char **arg)
{
	int	*argv;
	int	len;
	node *origin;

	if (argc != 2)
	{
		write(1, "Error, more than one arguement given\n", 37);
		return (0);
	}
	argv = split_to_i(arg[1]);
	len = 0;
	while (argv[len++ + 1])
	    ;
	if (len % 4 != 0)
		write(1, "invlid input, check for missing space or number\n", 48);
	g_n = len / 4;
	hash_init();
	origin = tab_init(g_n);
	assign_argv(origin, argv);
	free(argv);
	if (solve(origin, origin, origin))
	{
		print_tab(origin);
	}
	else
		write(1, "No solution\n", 12);
	free_all_node(origin);
}