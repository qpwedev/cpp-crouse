#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Macroprocessor.h"

void Macroprocessor::processCin()
{
    char c;

    while (std::cin.get(c))
    {
        if (c == '#' && IsspaceBefore)
        {
            if (!readMacro())
            {
                printAndClearBuffer();
                std::cout << "Error\n";
                return;
            }
            continue;
        }

        addCharOrResetIdentifier(c, IsalphaBefore);

        buffer += c;

        if (containsMacro(identifier))
        {
            buffer = buffer.substr(0, buffer.size() - identifier.size()) + macros[identifier];

            printAndClearBuffer();
        }

        updateIsFlags(c);
    }

    printAndClearBuffer();
}

bool Macroprocessor::readMacro()
{

    std::string macroName = readMacroName();
    if (macroName.size() == 0 || !isalpha(macroName[0]) || containsNonalnum(macroName))
    {
        return false;
    }

    resetIsFlags();

    std::string macroBody = readMacroBody();
    if (macroBody == "\0")
    {
        return false;
    }

    insertMacro(macroName, macroBody);
    resetIsFlags();

    return true;
}

std::string Macroprocessor::readMacroName()
{
    std::string macroName = "";

    char c;
    while (std::cin.get(c))
    {
        if (c == ' ')
        {
            break;
        }
        else
        {
            macroName += c;
        }
    }
    return macroName;
}

std::string Macroprocessor::readMacroBody()
{
    std::string macroBody = "";

    char c;
    while (std::cin.get(c))
    {
        if (c == '#' && IsspaceBefore)
        {
            if (macroBody[macroBody.size() - 1] == ' ')
            {
                macroBody = macroBody.substr(0, macroBody.size() - 1);
            }
            else
            {
                return "\0";
            }
            break;
        }

        macroBody += c;

        addCharOrResetIdentifier(c, IsalphaBefore);

        if (containsMacro(identifier))
        {
            macroBody = macroBody.substr(0, macroBody.size() - identifier.size()) + macros[identifier];
        }

        updateIsFlags(c);
    }
    return macroBody;
}

bool Macroprocessor::containsMacro(const std::string &identifier)
{
    return macros.count(identifier) ? true : false;
}

void Macroprocessor::addCharOrResetIdentifier(char c, bool IsalphaBefore)
{
    if (isalpha(c) || (IsalphaBefore && isalnum(c)) || (isdigit(c) && (identifier.size() > 0)))
    {
        identifier += c;
    }
    else if (!isalnum(c))
    {
        identifier = "";
    }
}

void Macroprocessor::addCmdMacro(int argc, char **argv)
{
    if (argc > 1)
    {
        std::vector<std::string> arg(argv, argv + argc);
        if (isalpha(arg[1][0]) && !containsNonalnum(arg[1]))
        {
            std::string body = "";
            for (size_t i = 2; i < arg.size(); ++i)
            {
                body += arg[i] + ' ';
            }
            if (body.size())
            {
                body = body.substr(0, body.size() - 1);
            }
            insertMacro(arg[1], body);
        }
    }
}

bool Macroprocessor::containsNonalnum(const std::string &word)
{
    int i = std::count_if(word.begin(), word.end(), [](char c)
                          { return !(std::isalnum(c)); });
    return i ? true : false;
}

void Macroprocessor::printAndClearBuffer()
{
    std::cout << buffer;
    identifier = "";
    buffer = "";
}

void Macroprocessor::insertMacro(const std::string &name, const std::string &body)
{
    macros.insert(std::pair<std::string, std::string>(name, body));
}

void Macroprocessor::updateIsFlags(char c)
{
    IsalnumBefore = isalnum(c) ? true : false;
    IsalphaBefore = isalpha(c) ? true : false;
    IsspaceBefore = isspace(c) ? true : false;
}

void Macroprocessor::resetIsFlags()
{
    IsalnumBefore = false;
    IsalphaBefore = false;
    IsspaceBefore = true;
    identifier = "";
}