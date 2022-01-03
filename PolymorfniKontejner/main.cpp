#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "ValStructs.h"
#include "Seznam.h"

using namespace std;

int main(int argc, char **argv)
{
    Seznam s;
    s.Add(make_unique<IntVal>(1));
    s.Add(make_unique<IntVal>(0));
    s.Add(make_unique<IntVal>(1));
    s.Add(make_unique<StringVal>("Hell"));
    s.Add(make_unique<IntVal>(0));
    s.PrintAll(false);
    std::cout << std::endl
              << "<----------------->" << std::endl;
    s.PrintAll(true);
    return 0;
}
