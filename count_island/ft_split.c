#define is_sep(x) (x == ' ' || x == '\n' || x == '\t')
#include <stdlib.h>

int len(char *str){
        int i = -1;
        while(str[++i]);
        return i;
}

void ft_strncpy(char *dest, char *src, int n){
        int i = -1;
        while (++i < n)
                dest[i] = src[i];
        dest[i] = 0;
}

char **ft_split(char *str){
        int i = -1, n = 0, wordc = 0;
        int start = 0;
        while (str[++i]){
                if (!is_sep(str[i]) && (i == 0 || is_sep(str[i - 1])))
                        wordc++;
        }
        char **tab = malloc(sizeof(char*) * (wordc + 1));
        i = 0;
        while (str[++i - 1]){
                if (!is_sep(str[i]) && (is_sep(str[i - 1])))
                        start = i;
                else if (!is_sep(str[i - 1]) && ((is_sep(str[i])) || !str[i])){
                        tab[n] = malloc((i - start) + 1);
                        ft_strncpy(tab[n++], &str[start], i - start);
                      }
        }
        tab[n] = (void*)0;
        return tab;
}

void free_txt_tab(char**tab){
    int i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}
