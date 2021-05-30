#include <iostream>
#include <vector>
using namespace std;
int main()
{   
    const size_t arr_size=6;
    int int_arr[arr_size] = {1,2,3,4,5,6};
    /*use array to intialize the vector*/
    vector<int> ivec(int_arr,int_arr+arr_size);
    return 0;
}