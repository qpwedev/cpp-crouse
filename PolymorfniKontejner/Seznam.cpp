#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "ValStructs.h"
#include "Seznam.h"

void Seznam::Add(std::unique_ptr<AbstractVal> value)
{
    values.push_back(move(value));
}

void Seznam::PrintAll(bool endLine = true)
{
    char endLineSymbol;
    if (endLine)
    {
        endLineSymbol = '\n';
    }
    else
    {
        endLineSymbol = ' ';
    }
    for (std::unique_ptr<AbstractVal> &value : values)
    {
        value->Print();
        std::cout << endLineSymbol;
    }
}
