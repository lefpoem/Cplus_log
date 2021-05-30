/*'##'tokenpaste operator*/
#include <stdio.h>
#define tokenpaste(n) printf("token" #n "=%d\n",token##n)
int main()
{
    int token34 = 40;
    tokenpaste(34);
    return 0;
}
// '##' cat two arguments
