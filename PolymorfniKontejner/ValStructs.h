#pragma once

struct AbstractVal
{
    virtual ~AbstractVal() {}

    virtual void Print() = 0;
};

struct IntVal : public AbstractVal
{
private:
    int value;

public:
    ~IntVal(){}
    IntVal(int v);

    void Print() override;
};

struct StringVal : public AbstractVal
{
private:
    std::string value;

public:
    ~StringVal(){}

    StringVal(std::string v);
    void Print() override;
};
