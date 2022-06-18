#include <unistd.h>

void writei(int number){
    // to array
    int all[32], placement = 1, i = 0, digit;
    while (number > placement) //there is still unread digit
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
