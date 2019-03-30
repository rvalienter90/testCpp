//
// Created by rvalienter90 on 3/30/19.
//

#include "threads.h"
// A dummy function
void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        cout << "Thread using function"
                " pointer as callable\n";
    }
}

// A callable object
class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "Thread using function"
                    " object as  callable\n";
    }
};

void callback(const std::string& data)
{
    std::cout << "Callback called because: " << data << '\n';
}
void task(int time)
{
    std::this_thread::sleep_for(std::chrono::seconds(time));
    callback("async task done");
}

void test_threads(){
    cout << "Threads 1 and 2 and 3 "
            "operating independently" << endl;

    // This thread is launched by using
    // function pointer as callable
    thread th1(foo, 3);

    // This thread is launched by using
    // function object as callable
    thread th2(thread_obj(), 3);

    // Define a Lambda Expression
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "Thread using lambda"
                    " expression as callable\n";
    };

    // This thread is launched by using
    // lamda expression as callable
    thread th3(f, 3);

    // Wait for the threads to finish
    // Wait for thread t1 to finish
    th1.join();

    // Wait for thread t2 to finish
    th2.join();

    // Wait for thread t3 to finish
    th3.join();
}


void test_threads2(){
    std::thread bt(task, 5);
    std::cout << "async task launched\n";
    std::this_thread::sleep_for(std::chrono::seconds(15));
    std::cout << "main done\n";
    // Wait for bt to finish
    bt.join();
}