#include <iostream>
#include<boost/coroutine2/all.hpp>
#include<boost/asio/ts/buffer.hpp>
void coroutine_function(boost::coroutines2::coroutine<void>::pull_type & coro_back)
{
    std::cout << "a ";
    coro_back();
    std::cout << "b ";
    coro_back(); 
    std::cout << "c ";
}

int main()
{
    boost::coroutines2::coroutine<void>::push_type coroutine_object(coroutine_function); 	// 创建协程
    std::cout << "1 ";
    coroutine_object();
    std::cout << "2 ";
    coroutine_object(); 
    std::cout << "3 ";
    coroutine_object();
    return 0;
}
