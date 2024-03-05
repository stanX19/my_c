#include <stdio.h>
#include <unistd.h>

int main()
{
    char c;

    c = 0;
    //while (c != '\n')
        read(1, &c, 1);
    printf("Hello World\n");
    c = 0;
    //while (c != '\n')
        read(1, &c, 1);
    printf("Second line\n");
    return 0;
}