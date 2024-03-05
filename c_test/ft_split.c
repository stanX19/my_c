#include <stdlib.h>
#include <stdio.h>

char *strdub(char*str, int start, int end){
    char*ret;
    int i;
    i = 0;
    if (!str || start >= end)
        return 0;
    ret = malloc(sizeof(char) * (end - start + 1));
    while (start < end){
        ret[i++] = str[start++];
    }
    ret[i] = 0;
    return ret;
}

void hash_init(int hash[127], char*sep){
    int i;
    
    i = 1;
    while (i < 127)
        hash[i++] = 0;
    i = 0;
    while (sep[i])
        hash[(int)sep[i++]] = 1;
    hash[0] = 1;
}

char**get_tab(int hash[127], char*str){
    int total;
    int idx;
    
    idx = -1;
    total = 1;
    while (str[++idx])
    {
        if (hash[(int)str[idx]] == 0 && hash[(int)str[idx + 1]] == 1)
            total++;
    }
    return malloc(sizeof(char*) * total);
}

char**ft_split(char*str, char*sep){
    char**ret;
    int hash[127];
    int idx;
    int start;
    int total;
    
    hash_init(hash, sep);
    ret = get_tab(hash, str);
    total = 0;
    start = 0;
    idx = -1;
    while (str[++idx]){
        if (hash[(int)str[idx]] == 1){
            if (start != idx)
                ret[total++] = strdub(str, start, idx);
            start = idx + 1;
        }
    }
    if (start != idx)
        ret[total++] = strdub(str, start, idx);
    ret[total] = 0;
    return ret;
}