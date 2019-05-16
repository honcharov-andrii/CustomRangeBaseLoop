#include <iostream>

#include "customcontainer.h"

int main(int argc, char *argv[])
{
    CustomContainer<size_t> container(10);

    for(size_t i = 0; i < 10; ++i)
    {
        container[i] = i;
    }

    for(auto it : container)
    {
        std::cout << it << std::endl;
    }

    return 0;
}
