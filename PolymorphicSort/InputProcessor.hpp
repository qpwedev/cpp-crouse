#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "LinesProcessor.hpp"

class InputProcessor
{
    std::vector<std::string> args;
    std::string inputFileName = "";
    std::unordered_map<int, char> columnConfiguration;

public:
    std::string outputFileName = "";
    char separator = ' ';
    
    InputProcessor(std::vector<std::string> &args)
    {
        this->args = args;
    }

    std::vector<int> comparitionIndeces;

    std::string yieldArgument();

    void processFlag(std::string &arg);

    bool isNumber(std::string &number);

    void addConfiguration(std::string &arg);

    void processColumnConfiguration(std::string &arg);

    void processArgs();

    void processInput(LinesProcessor &linesProcessor);

    void parseLine(std::string &line, LinesProcessor &linesProcessor, int row);
};
