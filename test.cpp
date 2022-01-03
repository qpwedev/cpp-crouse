#include <vector>
#include <string>
#include <memory>
#include <iostream>


struct CopyableStructure
{
    std::vector<std::string> data;
};

struct NotCopyableStructure
{
    std::unique_ptr<int> data;
};

int main()
{
    {
        CopyableStructure original;
        CopyableStructure copy(original);
        copy.data.push_back("hello");
        std::cout <<  copy.data[0];
    }
    
    // {
    //     NotCopyableStructure original;
    //     // does not compile because std::unique_ptr does not have copy constructor
    //     // so copy constructor of NotCopyableStructure is not implicitly generated
    //     NotCopyableStructure copy(original); 
    // }

    return 0;
}
