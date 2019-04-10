#define _GLIBCXX_USE_NANOSLEEP
#include <iostream>
#include <string>
//#include "threads.h"
//#include "plots.h"
//#include "randon.h"
#include "pthreads.h"
int main()
{
    std::cout << "Hello, World!" << std::endl;

   /* */
//test_pthread0();
//test_pthread();
    //test_pthread_sleep();


 //test_plot_basic();
// test_plot_func_cont();
// test_plot_scatter_cont();
   // test_threads();
    //test_threads2();
//test_randon_unif();
//test_rand();
    test_pthread_sleep_recurrent();
    int count=0;
while (1){



    auto start = std::chrono::high_resolution_clock::now();
    sleep(2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    //std::cout << "Waited in main " << elapsed.count() << " ms\n";
    count++;
    if (count> 6)
        break;

}
//
}

