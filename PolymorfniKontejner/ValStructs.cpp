#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ValStructs.h"

IntVal::IntVal(int v)
{
    value = v;
}

void IntVal::Print()
{
    std::cout << value;
}

StringVal::StringVal(std::string v)
{
    value = v;
}

void StringVal::Print()
{
    std::cout << value;
}
