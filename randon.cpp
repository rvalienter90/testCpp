//
// Created by rvalienter90 on 3/30/19.
//

#include "randon.h"

void test_randon_unif(){
    std::mt19937_64 rng;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);
    // ready to generate random numbers
    const int nSimulations = 10;
    for (int i = 0; i < nSimulations; i++)
    {
        double currentRandomNumber = unif(rng);
        std::cout << currentRandomNumber << std::endl;
    }
}
void test_rand(){

    srand(time(NULL));

    for (int i = 10; i > 0; i--) //try it thousand times
    {
        double randnum = (double)rand() / ((double)RAND_MAX + 1);
        std::cout << " rnum: " << randnum << std::endl;
        std::cout << " rnum: " << rand()%5 << std::endl;
    }
}