#include <experimental/coroutine>

//using generator = std::experimental::generator<int>;

generator GenerateIntegers()
{
    for(int i=0; i<5; i++)
    {
        co_yield i;
    }
}

int main()
{
    return 0;
}