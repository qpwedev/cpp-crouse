#pragma once

#include "InputProcessor.hpp"
#include "Cell.hpp"

#include <fstream>
#include <memory>
#include <algorithm>

typedef std::vector<std::shared_ptr<AbstractCell>> CellsVector;

struct Comparator
{
    std::vector<int> comparitionIndeces;

public:
    Comparator(std::vector<int> &comparitionIndeces) : comparitionIndeces(comparitionIndeces) {}

    bool operator()(const CellsVector &a, const CellsVector &b)
    {
        for (auto i : comparitionIndeces)
        {
            if (*(a[i]) == *(b[i]))
            {
                continue;
            }
            else
            {
                return (*(a[i]) < *(b[i]));
            }
        }
        return true;
    }
};

class LinesProcessor
{
public:
    std::vector<CellsVector> lines;

    inline void sort(std::vector<int> &comparitionIndeces)
    {
        std::sort(lines.begin(), lines.end(), Comparator(comparitionIndeces));
    }

    inline void push_back(CellsVector cells)
    {
        lines.push_back(cells);
    }

    void write_lines(char separator, std::ostream &ofs)
    {
        for (auto line : lines)
        {
            long unsigned int counter = 0;
            for (auto cell_ptr : line)
            {
                ofs << (*cell_ptr).to_string();
                if (counter != line.size() - 1)
                {
                    ofs << separator;
                }
                ++counter;
            }
            ofs << '\n';
        }
    }

    void write_output(char separator, std::string &outputFileName)
    {
        if (outputFileName == "")
        {
            write_lines(separator, std::cout);
        }
        else
        {
            std::ofstream ofs(outputFileName);
            if (!ofs.good())
            {
                return;
            }
            write_lines(separator, ofs);
            ofs.close();
        }
    }
};
