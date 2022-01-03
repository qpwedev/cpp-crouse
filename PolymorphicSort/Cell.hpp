#pragma once

class AbstractCell
{
public:
    virtual bool operator<(const AbstractCell &cell) const = 0;
    virtual bool operator==(const AbstractCell &cell) const = 0;
    virtual std::string to_string() const = 0;

    virtual ~AbstractCell() {}
};

class NumericCell : public AbstractCell
{
public:
    int value;

    NumericCell(int v) : value(v) {}

    bool operator<(const AbstractCell &cell) const override
    {
        const NumericCell &n_cell = static_cast<const NumericCell &>(cell);
        if (this->value < n_cell.value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator==(const AbstractCell &cell) const override
    {
        const NumericCell &n_cell = static_cast<const NumericCell &>(cell);
        if (this->value == n_cell.value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string to_string() const override { return std::to_string(value); }

    ~NumericCell() {}
};

class StringCell : public AbstractCell
{
public:
    std::string value;
    StringCell(std::string v) : value(v) {}

    bool operator<(const AbstractCell &cell) const override
    {
        const StringCell &s_cell = static_cast<const StringCell &>(cell);

        if (this->value < s_cell.value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator==(const AbstractCell &cell) const override
    {
        const StringCell &n_cell = static_cast<const StringCell &>(cell);
        if (this->value == n_cell.value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string to_string() const override { return value; }

    ~StringCell() {}
};
