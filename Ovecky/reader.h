#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Reader
{
public:
    int wordCounter = 0;
    int charCounter = 0;
    int sentenceCounter = 0;
    int lineCounter = 0;
    int numberCounter = 0;
    int numberSum = 0;
    int wordsOnLine = 0;
    bool nonalphanum = false;

    void readStream(std::istream &from);
    std::string readWord(std::istream &from);
    int detectTypeOfWord(std::string word);
    bool detectEndOfSentence(std::string word);
};

#endif