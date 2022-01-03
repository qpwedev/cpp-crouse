#include <string>
#include <vector>

#include "InputProcessor.hpp"
#include "LinesProcessor.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv + 1, argv + argc);

    InputProcessor inputProcessor(args);
    LinesProcessor LinesProcessor;

    inputProcessor.processArgs();
    inputProcessor.processInput(LinesProcessor);

    LinesProcessor.sort(inputProcessor.comparitionIndeces);
    LinesProcessor.write_output(inputProcessor.separator, inputProcessor.outputFileName);
}
