#include <boost/asio/yield.hpp>
#include <iostream>

struct task : boost::asio::coroutine
{
    int i = 0;

    void operator()()
    {
        reenter (this)
        {
            while (i < 5)
            {
                i++;
                std::cout<< i <<std::endl;
                yield;
                i++;
                std::cout<< i <<std::endl;
                yield;
            }
        }
    }
};

int main() 
{
    task t1;

    for (int i = 0; i < 10; i++)
    {
        t1();
        std::cout<< "from main" <<std::endl;
    }

    return 0;
}

