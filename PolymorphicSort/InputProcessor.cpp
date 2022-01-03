#include "InputProcessor.hpp"

std::string InputProcessor::yieldArgument()
{
    static long unsigned int index = 0;
    if (index < args.size())
    {
        return args[index++];
    }
    else
    {
        return "";
    }
}

void InputProcessor::processFlag(std::string &arg)
{
    if (arg[1] == 'i')
    {
        if (arg.size() == 2)
        {
            inputFileName = yieldArgument();
        }
        else
        {
            inputFileName = arg.substr(2);
        }
    }
    else if (arg[1] == 'o')
    {

        if (arg.size() == 2)
        {
            outputFileName = yieldArgument();
        }
        else
        {
            outputFileName = arg.substr(2);
        }
    }
    else if (arg[1] == 's')
    {

        if (arg.size() == 2)
        {
            separator = yieldArgument()[0];
        }
        else
        {
            separator = arg.substr(2)[0];
        }
    }
    else
    {
        exit(0);
    }
}

bool InputProcessor::isNumber(std::string &number)
{
    bool isNumber = true;
    for (auto n : number)
    {
        if (!isdigit(n))
        {
            isNumber = false;
        }
    }
    return isNumber;
}

void InputProcessor::addConfiguration(std::string &arg)
{
    char columnType = arg[0];
    std::string potentialNumber = arg.substr(1);
    if (isNumber(potentialNumber))
    {
        columnConfiguration[std::stoi(potentialNumber) - 1] = columnType;
        comparitionIndeces.push_back(std::stoi(potentialNumber) - 1);
    }
}

void InputProcessor::processColumnConfiguration(std::string &arg)
{
    if ((arg[0] == 'N' || arg[0] == 'S') && arg.size() >= 2)
    {
        addConfiguration(arg);
    }
    else
    {
        exit(0);
    }
}

void InputProcessor::processArgs()
{
    auto arg = yieldArgument();
    while (arg != "")
    {
        if (arg[0] == '-' && arg.size() >= 2)
        {
            processFlag(arg);
        }
        else
        {
            processColumnConfiguration(arg);
        }
        arg = yieldArgument();
    }
}

void InputProcessor::processInput(LinesProcessor &linesProcessor)
{
    int row = 0;

    if (inputFileName == "")
    {
        std::istream &inputSource = std::cin;

        while (!inputSource.eof())
        {
            std::string line;
            std::getline(std::cin, line);

            parseLine(line, linesProcessor, row);
            ++row;
        }
    }
    else
    {
        std::ifstream ifs;
        ifs.open(inputFileName);

        if (!ifs.good())
        {
            exit(0);
        }

        std::istream &inputSource = ifs;

        while (!inputSource.fail())
        {
            std::string line;
            std::getline(ifs, line);

            parseLine(line, linesProcessor, row);
            ++row;
        }
    }
}

void InputProcessor::parseLine(std::string &line, LinesProcessor &linesProcessor, int row)
{
    if (line == "")
    {
        return;
    }
    std::string token = "";
    line += separator;
    CellsVector parsedLine;

    int column = 0;
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (line[i] != separator)
        {
            token += line[i];
        }
        else
        {
            if (columnConfiguration.count(column) != 0 & columnConfiguration[column] == 'N' & isNumber(token))
            {

                if (isNumber(token))
                {
                    parsedLine.push_back((std::make_shared<NumericCell>(std::stoi(token))));
                }
                else
                {
                    std::cerr << "error: radka " << row + 1 << ", sloupec " << column + 1 << " - nepripustny format" << std::endl;
                    exit(0);
                }
            }
            else
            {
                parsedLine.push_back(std::make_shared<StringCell>(token));
            }
            token = "";
            ++column;
        }
    }

    linesProcessor.push_back(std::move(parsedLine));
}
