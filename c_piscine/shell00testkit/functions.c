#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void print_diff(char *command, char* expected, char* result){
	printf("\nCommand: \n%s\n", command);
	printf("Expected:\n%s\nOutput:\n", expected);
	if (result)
		printf("%s", result);
	printf("\n");
}

int    ft_strcmp(char * s1, char * s2)
{
    unsigned int    i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
    return (s1[i] - s2[i]);
}

void free_double(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}

int exists(char *path) {
	int fd = open(path, O_RDONLY);
	if (fd < 0)
		return 0;
	close(fd);
	return 1;
}

char *read_file(char *path){
	int f;
	char *result = malloc(1025);

	memset(result, 0, 1025);
	f = open(path, O_RDONLY);
	if (f < 0)
		return 0;
	read(f, result, 1024);
	close(f);
	return result;
}

int find(char* str, char c) {
	for (int i = 0; str[i]; i++) {
		if (str[i] == c)
			return i;
	}
	return -1;
}

int	not_sep(char c, char* charset)
{
	int i;

	i = 0;

	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	countword(char* str, char* charset)
{
	int count;
	char* s;

	count = 0;
	s = str;
	while (*s)
	{
		if (not_sep(*s, charset))
		{
			++count;
			while (*s && not_sep(*s, charset))
				++s;
		}
		else
			++s;
	}
	return (count);
}

int	countchar(char* str, char* charset)
{
	int countchar;

	countchar = 0;
	while (*str && not_sep(*str++, charset))
		++countchar;
	return (countchar);
}

int ft_strlen(char* str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char** ft_split(char* str, char* charset)
{
	char** res;
	int arr_size;
	int i;
	int j;

	i = 0;
	arr_size = countword(str, charset) + 1;
	res = malloc(sizeof(char*) * (arr_size));
	if (!res)
		return (NULL);
	res[0] = 0;
	if (*str == '\0')
		return (res);
	if (*charset == '\0')
	{
		j = 0;
		res[0] = malloc(sizeof(char) * ft_strlen(str) + 1);
		while (*str)
			res[0][j++] = *str++;
		res[0][j] = '\0';
		res[1] = 0;
		return (res);
	}
	while (*str)
	{
		j = 0;
		if (not_sep(*str, charset))
		{
			res[i] = malloc(sizeof(char) * countchar(str, charset) + 1);
			while (not_sep(*str, charset) && *str)
			{
				res[i][j++] = *str;
				++str;
			}
			res[i][j] = '\0';
			++i;
		}
		else
			++str;
	}
	res[i] = 0;
	return (res);
}

int cwd_is_empty(void) {
	int ret = 0;

	system("ls>result.txt");
	char* result = read_file("result.txt");
	if (ft_strcmp(result, "result.txt\n") == 0)
		ret = 1;
	free(result);
	return ret;
}