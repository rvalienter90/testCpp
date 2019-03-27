#define _GLIBCXX_USE_NANOSLEEP
#include <iostream>
#include <string>
#include <thread>
void callback(const std::string& data)
{
    std::cout << "Callback called because: " << data << '\n';
}
void task(int time)
{
    std::this_thread::sleep_for(std::chrono::seconds(time));
    callback("async task done");
}
int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::thread bt(task, 5);
    std::cout << "async task launched\n";
    std::this_thread::sleep_for(std::chrono::seconds(15));
    std::cout << "main done\n";
    bt.join();
}