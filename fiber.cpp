#include <boost/fiber/fiber.hpp>
#include <boost/fiber/mutex.hpp>
#include <boost/fiber/barrier.hpp>
#include <boost/fiber/algo/algorithm.hpp>
#include <boost/fiber/algo/work_stealing.hpp>

namespace bf = boost::fibers;



class GreenExecutor
{
    std::thread worker;
    bf::condition_variable_any cv;
    bf::mutex mtx;
    bf::barrier barrier;
public:
    GreenExecutor() : barrier {2}
    {
        bf::use_scheduling_algorithm<bf::algo::work_stealing>(2);

        worker = std::thread([this] {
            bf::use_scheduling_algorithm<bf::algo::work_stealing>(2);
            // wait till all threads joining the work stealing have been registered
            barrier.wait();
            mtx.lock();
            // suspend main-fiber from the worker thread
            cv.wait(mtx);
            mtx.unlock();
        });
        // wait till all threads have been registered the scheduling algorithm
        barrier.wait();
    }

    template<typename T>
    void PostWork(T&& functor)
    {
        bf::fiber {std::move(functor)}.detach();
    }

    ~GreenExecutor()
    {
        cv.notify_all();
        worker.join();
    }
};

int main()
{
    GreenExecutor executor;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int i = 0;
    for (auto j = 0ul; j < 10; ++j) {
        executor.PostWork([idx {++i}]() {
            auto res = pow(sqrt(sin(cos(tan(idx)))), M_1_PI);
            std::cout << idx << " - " << res << std::endl;
        });
    }
    while (true) {
        boost::this_fiber::yield();
    }
    return 0;
}