#include <unistd.h>

void writei(int number){
    // to array
    int all[32], placement = 1, i = 0, digit;
    if (number == 0)
        write(1, "0", 1);
    while (number >= placement) //there is still unread digit
    { 
        digit = ( number % (placement*10) ) / placement; // get current digit
        digit += 48;
        all[i] = digit;
        
        placement *= 10; // move to next digit
        i++;
    }
    // print 1 by 1
    int len = i;
    write(1,"",0);
    while (i != -1){
        i--;
        digit = all[i];
        write(1,&digit,1);
    }
}

void    swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void    print_arr(int *array, int len)
{
    int i;
    
    i = 0;
    write(1, "{", 1);
    while (i < len)
    {
        writei(array[i]);
        if (i != len-1)
            write(1, ", ", 2);
        i++;
    }
    write(1, "}", 1);
}

void bubble_sort(int *array, int len)
{
    int sorted = 0;
    int i = 0;
    while (sorted != len - 1)
    {
        sorted = 0;
        while (i < len - 1)
        {
            if (array[i] > array[i + 1])
                swap(&array[i], &array[i + 1]);
            else
                sorted++;
            i++;
        }
        i = 0;
    }
}
