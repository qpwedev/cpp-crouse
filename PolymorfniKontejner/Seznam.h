#pragma once

class Seznam
{
    std::vector<std::unique_ptr<AbstractVal>> values;

public:
    void Add(std::unique_ptr<AbstractVal> value);
    void PrintAll(bool endLine);
    Seznam() {}
    Seznam(const Seznam &s) = delete;
    Seznam &operator=(const Seznam &s) = delete;
};