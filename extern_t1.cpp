#include <stdio.h>
int count;
extern void write_extern();//extern share files,extern member  explicitly initialiazed to 0
int main()
{
    count = 5;
    write_extern();
    return 0;
}
