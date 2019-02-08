#include <cstdlib>
#include <iostream>
#include <boost/coroutine2/all.hpp>

typedef boost::coroutines2::coroutine< int >::pull_type PULL_TYPE;
typedef boost::coroutines2::coroutine< int >::push_type PUSH_TYPE;

int main() {
    PULL_TYPE source([](PUSH_TYPE & sink) 
    {
        int first = 1, second = 1;
        sink( first);
        sink( second);
        for ( int i = 0; i < 8; ++i) 
        {
            int third = first + second;
            first = second;
            second = third;
            sink( third);
        }
    });

    for ( auto i : source) 
    {
        std::cout << i <<  " ";
    }
    std::cout << "\nDone" << std::endl;
    return 0;
}