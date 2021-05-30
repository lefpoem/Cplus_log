#include <stdio.h>
static int count = 10; //global scope,it is invisible to other files
void func1(void);
int main()
{
    while(count--)
      func1();
    return 0;
}
void func1(void)
{
    static int thingy = 5;//local member,static thingy is initialized one time.
    int mhingy = 4;// local member,each call,mhingy is initialized to 4.
    thingy++;   //static member thingy explicitly initialiazed to 0;
    mhingy++;
    printf("thingy is %d ,mhingy is %d\n , count is %d\n",thingy,mhingy,count);
}