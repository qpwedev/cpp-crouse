#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

class BrainfuckInterpreter
{
    char array[30000] = {0};
    char *ptr = array;
    int parentheses = 0;
    vector<int> stack;
    string input;
    int current_position = 0;

    void skip()
    {
        int p_state = parentheses;
        while (parentheses != (p_state - 1))
        {
            ++current_position;
            char char_ = get_char();
            switch (char_)
            {
            case '[':
                ++parentheses;
                break;

            case ']':
                --parentheses;
                break;

            default:
                break;
            }
        }
    }

    void add_to_stack()
    {
        stack.push_back(current_position);
    }

    void jump_back()
    {
        auto value = stack.back();
        current_position = value;
        stack.pop_back();
    }

    char get_char()
    {
        if (current_position < input.length())
        {
            return input[current_position];
        }
        else
        {
            return '\0';
        }
    }

public:
    BrainfuckInterpreter(string input)
    {
        this->input = input;
    }

    void process_code()
    {
        char char_;
        do
        {
            char_ = get_char();

            switch (char_)
            {
            case '>':
                ++ptr;
                break;

            case '<':
                --ptr;
                break;

            case '+':
                ++(*ptr);
                break;

            case '-':
                --(*ptr);
                break;

            case '.':
                putchar(*ptr);
                break;

            case ',':
                *ptr = getchar();
                break;

            case '[':
                if (*ptr)
                {
                    ++parentheses;
                    add_to_stack();
                }
                else
                {
                    skip();

                    break;

                case ']':
                    --parentheses;
                    jump_back();
                    continue;
                    break;

                default:
                    break;
                }

                ++current_position;
            }
        } while (char_ != '\0');
    }
};

int main(int argc, char **argv)
{

    string input = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    BrainfuckInterpreter brainfuck(input);
    brainfuck.process_code();

    return 0;
}
