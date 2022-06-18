#include <unistd.h>

int contains(char *str, char c)
{
    char *s1 = str;
    char cc = c;
    int i = 0;
    while (str[i])
    {
        if (str[i++] == c)
            return 1;
    }
    return 0;
}

int ncontains(char *str, char c, int n)
{
    int i = 0;
    while (i < n)
    {
        if (str[i++] == c)
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 3){
        int i = 0;
        char *str1 = argv[1];
        char *str2 = argv[2];
        while (str1[i]){
            if (!ncontains(str1, str1[i], i))
                write(1, &str1[i], 1);
            i++;
        }
        i = 0;
        while (str2[i]) {
            if (!ncontains(str2, str2[i], i) && !contains(str1, str2[i]))
                write(1, &str2[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
