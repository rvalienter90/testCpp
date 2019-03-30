#define _GLIBCXX_USE_NANOSLEEP
#include <iostream>
#include <string>
#include "threads.h"
#include "plots.h"
#include "randon.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;

   /* */

 //test_plot_basic();
// test_plot_func_cont();
// test_plot_scatter_cont();
   // test_threads();
    //test_threads2();
test_randon_unif();
test_rand();

}