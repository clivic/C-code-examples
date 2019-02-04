#ifndef UTILITY
#define UTILITY

#include <iostream>
#include <Queue>
#include <cstdlib>

using namespace std;
 
bool UserSayYes();

template <class Type>
extern void Cin(/* inout */ Type& input);

enum Error_code {success, underflow, overflow, range_error};

#endif