#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char* exists(char* path);

int	ft_strcmp(char *s1, char *s2);

char* read_file(char* path);

void print_diff(char* command, char* expected, char* result);

int dir_is_empty(void);

int test00(void)
{
	char *command;
	char *expected;
	char *result;

	if (dir_is_empty())
		return 2;
	if (!exists("z"))
		return 3;
	expected = "Z\n";
	command = "cat z >result.txt";
	system(command);
	result = read_file("result.txt");
	if (result){
		if (ft_strcmp(result, expected) == 0){
			free(result);
			return 1;
		}
	}	
	print_diff(command, expected, result);
	free(result);
	return 0;
}
