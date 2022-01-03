#include <string>
#include <vector>
#include <unordered_map>
#include "Macroprocessor.h"

int main(int argc, char **argv)
{
    Macroprocessor macroprocessor;
    macroprocessor.addCmdMacro(argc, argv);
    macroprocessor.processCin();
}
