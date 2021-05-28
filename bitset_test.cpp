#include <iostream>
#include <bitset>
using std::bitset;
bitset<32> ivec; //32 bits,all zero
bool is_set=ivec.any();
bool is_not_set=ivec.none();
size_t bits_set = ivec.count();
