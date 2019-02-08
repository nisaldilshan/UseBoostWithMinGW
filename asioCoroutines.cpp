#include <boost/asio/yield.hpp>
#include <iostream>

// struct session : boost::asio::coroutine
// {
//   boost::shared_ptr<tcp::socket> socket_;
//   boost::shared_ptr<std::vector<char> > buffer_;

//   session(boost::shared_ptr<tcp::socket> socket)
//     : socket_(socket),
//       buffer_(new std::vector<char>(1024))
//   {
//   }

//   void operator()(boost::system::error_code ec = boost::system::error_code(), std::size_t n = 0)
//   {
//     if (!ec) reenter (this)
//     {
//       for (;;)
//       {
//         yield socket_->async_read_some(boost::asio::buffer(*buffer_), *this);
//         yield boost::asio::async_write(*socket_, boost::asio::buffer(*buffer_, n), *this);
//       }
//     }
//   }
// };

struct task : boost::asio::coroutine
{
    int i = 0;

    int& operator()(int& num)
    {
        reenter (this)
        {
            while (i < 5)
            {
                i++;
                yield std::cout<< "i = " << i <<std::endl;
                i++;
                std::cout<< "i = " << i <<std::endl;
                yield;
                num++;
            }
        }

        return i;
    }
};

int main() 
{
    task t1;

    int&& num = int(1);

    for (int i = 0; i < 10; i++)
    {
        std::cout<< "from main, i : "<<std::endl<< t1(num) <<std::endl;
        std::cout<< "from main, num : " << num <<std::endl;
    }

    return 0;
}

