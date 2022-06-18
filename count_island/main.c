#include "island.h"

char *read_file(char * path)
{
	int f = open(path, O_RDONLY);
	if (f < 0)
		return (void*)0;
	char *txt = malloc(1050625);
	read(f, txt, 1024);
	close(f);
	return txt;
}

int main(int argc, char **argv)
{
	if (argc != 2){
		write(1, "\n", 1);
		return 0;
	}
	char *txt = read_file(argv[1]);
	if (!txt){
		write(1, "\n", 1);
		return 0;
	}
	char **txt_tab = ft_split(txt);
	node *origin = char_tab_to_node(txt_tab);
	char i = '0';
	node *row = origin;
	node *current;
	while (row){
		current = row;
		while (current){
			if (current->data == 'X'){
				current->data = i;
				spread(current, 'X');
				i++;
			}
			current = current->right;
		}
		row = row->bot;
	}
	print_tab(origin);

	free(txt);
	free_txt_tab(txt_tab);
	free_all_node(origin);
}
