#pragma once

class Macroprocessor
{
    bool IsspaceBefore;
    bool IsalnumBefore;
    bool IsalphaBefore;
    std::string identifier;
    std::string buffer;
    std::unordered_map<std::string, std::string> macros;

public:
    Macroprocessor() : IsspaceBefore(true), IsalnumBefore(false), IsalphaBefore(false), identifier(""), buffer("")
    {
    }

    void processCin();
    void addCmdMacro(int argc, char **argv);

private:
    bool containsNonalnum(const std::string &word);
    bool containsMacro(const std::string &identifier);
    void insertMacro(const std::string &name, const std::string &body);
    bool readMacro();
    void updateIsFlags(char c);
    void printAndClearBuffer();
    void resetIsFlags();
    std::string readMacroBody();
    std::string readMacroName();
    void addCharOrResetIdentifier(char c, bool IsalphaBefore);
};