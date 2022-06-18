#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int	ft_strcmp(char *s1, char *s2);

char **ft_split(char *str, char *charset);

void free_double(char **tab);

void print_diff(char* command, char* expected, char* result);

char* read_file(char* path);

int exists(char* path);

int find(char* str, char c);

int dir_is_empty(void);

int test02(void)
{
	int ret = 1;
	char *expected;
	char *result;
	char **words;
	char **expected_words;
	char *command;

	expected = "total XX\
\ndrwx--xr-x 1 XX XX XX Jun 2 20:47 test0\
\n-rwx--xr-- 1 XX XX 4 Jun 1 21:46 test1\
\ndr-x---r-- 2 XX XX XX Jun 1 22:45 test2\
\n-r-----r-- 2 XX XX 1 Jun 1 23:44 test3\
\n-rw-r----x 1 XX XX 2 Jun 1 23:43 test4\
\n-r-----r-- 2 XX XX 1 Jun 1 23:44 test5\
\nlrwxr-xr-x 1 XX XX 5 Jun 1 22:20 test6->test0\n";

	command = "tar -xf exo2.tar -C ex02 && ls -l > result.txt";

	if (dir_is_empty())
		return 2;
	if (!exists("exo2.tar"))
		return 3;
	system("mkdir ex02 && tar -xf exo2.tar -C ex02");
	system("ls -l ex02 > result.txt");
	result = read_file("result.txt");
	words = ft_split(result, " \n");
	expected_words = ft_split(expected, " \n");
	for (int i = 0; words[i]; i++) {
		printf("%s$\n", words[i]);
		if (ft_strcmp(expected_words[i], "XX") != 0 && ft_strcmp(words[i], expected_words[i]) != 0) {
			if ((i - 2) % 7 == 0 && find(words[i], ':') == -1)
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
