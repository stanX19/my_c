#include <unistd.h>

void putnbr(int nb)
{
    char c = (nb % 10) + '0';
    if (nb > 10)
        putnbr(nb / 10);
    write(1, &c, 1);
}
int main()
{
    int i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0)
            write(1, "fizz", 4);
        if (i % 5 == 0)
            write(1, "buzz", 4);
        if (i % 5 != 0 && i % 3 != 0)
            putnbr(i);
        write(1, "\n", 1);
        i++;
    }
}
