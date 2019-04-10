//
// Created by nsl on 4/10/19.
//

#ifndef TESTCPP_PTHREADS_H
#define TESTCPP_PTHREADS_H
#include <pthread.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <chrono>
//pthread_create (thread, attr, start_routine, arg)
//Compile the following program using -lpthread library as follows  gcc test.cpp -lpthread
using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid);
void *print_test(void *threadid);
void test_pthread();
void test_pthread0();
void test_pthread_sleep();

void test_pthread_sleep_recurrent();
//const auto timeWindow = std::chrono::milliseconds(50);
//const auto timeWindow_read = std::chrono::milliseconds(100);
void *recurrent_function(void *threadid);

#endif //TESTCPP_PTHREADS_H
