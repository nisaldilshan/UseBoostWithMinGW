#include <boost/stacktrace.hpp>
#include <iostream>

// ... somewhere inside the `bar(int)` function that is called recursively:
int main()
{
    std::cout << boost::stacktrace::stacktrace();
    return 0;
}

