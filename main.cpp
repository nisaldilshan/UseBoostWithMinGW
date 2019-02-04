#include <iostream>
#include <cmath>
#include <boost/chrono/chrono.hpp>

int main()
{
    auto start = boost::chrono::system_clock::now();

    for ( long i = 0; i < 10000000; ++i )
        std::sqrt( 123.456L ); // burn some time

    boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
    std::cout << "took " << sec.count() << " seconds\n";
    return 0;
}