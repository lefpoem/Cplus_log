#include <stdio.h>
int main()
{
    int c;
    printf("please input :");
    while((c = getchar())!=EOF)
         putchar(c);
    printf("EOf = %d/n",EOF);
    return 0;
}
