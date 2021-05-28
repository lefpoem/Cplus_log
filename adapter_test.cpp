#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
using namespace std;
/*stack builds on vector,list,deque
 *queue require push_front,so build on list
 *priority_queue require random access,building on vector,deque 
 *stack supports empty,size,pop,push,
 *stack don't use directly operation of container*/
int main()
{
    deque<int> deq;
    stack<int> stk(deq);//copies elements from deq into stk
    const stack<int>::size_type stk_size = 10;
    stack<int> intstack; //empty stack
    // fill up the stack
    int ix = 0;
    while (intstack.size()!= stk_size)
    {
        //use postfix increment; want to push old value onto s
        intstack.push(ix++);//s holds 0~9 inclusive
    }
    int error_cnt = 0;
    //look at each value and pop it off the stack
    while (intstack.empty()==false)
    {
        int value =intstack.top();
        //read the top element of the stack
        if (value!=--ix)
        {
            cerr << "oops! expected" << ix << "received" << value <<endl;
            ++error_cnt;
        }
        intstack.pop(); //pop the top element,and repeat;
    }
    cout << "Our program ran with "
         << error_cnt << " errors!" << endl;
    return 0;
}
