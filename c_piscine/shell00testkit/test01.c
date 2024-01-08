#include <unistd.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2);

char **ft_split(char *str, char *charset);

void free_double(char **tab);

void print_diff(char* command, char* expected, char* result);

char* read_file(char* path);

int exists(char* path);

int find(char* str, char c);

int cwd_is_empty(void);

int test01(void)
{
	int ret = 1;
	char *expected;
	char *result;
	char **words;
	char **expected_words;
	char *command;

	expected = "-r--r-xr-x 1 XX XX 40 Jun 1 23:42 testShell00\n";
	command = "tar -xf testShell00.tar && ls -l testShell00 > result.txt";
	if (cwd_is_empty())
		return 2;
	if (!exists("testShell00.tar"))
		return 3;
	system("tar -xf testShell00.tar");
	system("ls -l testShell00 > result.txt");
	result = read_file("result.txt");
	words = ft_split(result, " ");
	expected_words = ft_split(expected, " ");
	for (int i = 0; words[i]; i++) {
		if (i != 2 && i != 3 && ft_strcmp(words[i], expected_words[i]) != 0){
			if (i == 7 && find(words[i], ':') == -1)
				continue;
			print_diff(command, expected, result);
			ret = 0;
			break;
		}
	}
	free(result);
	free_double(words);
	free_double(expected_words);
	return ret;
}
