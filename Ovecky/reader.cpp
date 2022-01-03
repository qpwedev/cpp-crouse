#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "reader.h"

using namespace std;

void Reader::readStream(istream &source)
{
    string word = readWord(source);

    while (word != "")
    {
        switch (detectTypeOfWord(word))
        {
        case 1:
            ++numberCounter;
            break;
        case 2:
            ++wordCounter;
            ++wordsOnLine;
            break;
        }
        if (detectEndOfSentence(word))
        {
            ++sentenceCounter;
        }

        ++wordCounter;
        cout << word << endl;
        word = readWord(source);
        detectTypeOfWord(word);
    }
}

bool Reader::detectEndOfSentence(std::string word)
{
    if (word[word.length() - 1] == '.' || word[word.length() - 1] == '!' || word[word.length() - 1] == '?')
        return true;
    return false;
}

int Reader::detectTypeOfWord(string word)
{
    if (!isalnum(word[0]))
    {
        string number = "";
        for (size_t i = 1; i < word.length(); ++i)
        {
            if (!isnumber(word[i]))
            {
                break;
            }
            else
            {
                number += word[i];
            }
        }
        if (number != "")
        {
            numberCounter += stoi(number);
        }

        return number != "" ? 1 : 0;
    }
    else if (!isdigit(word[0]))
    {
        bool isword = true;

        for (size_t i = 1; i < word.length(); ++i)
        {
            if (!isalpha(word[i]))
            {
                isword = false;
            }
        }

        return isword ? 2 : 0;
    }
    return -1;
}

string Reader::readWord(std::istream &source)
{
    string word = "";

    while (!source.fail())
    {
        char c = source.get();
        ++charCounter;

        if (c == '\n' && wordsOnLine > 0)
        {
            ++lineCounter;
            wordsOnLine = 0;
        }
        if (!isblank(c) && c != '\n')
        {
            word += c;
        }
        else if (word != "")
        {
            return word;
        }
    }

    if (wordsOnLine > 0)
    {
        ++lineCounter;
    }

    return word;
}