//
// Created by nsl on 5/13/19.
//

#include "timetest.h"

using namespace std;


void test_time(){
    // how to measure execution time using time() function.

    /* Time function returns the time since the
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;

    /* You can call it like this : start = time(NULL);
     in both the way start contain total time in seconds
     since the Epoch. */
    time(&start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    usleep(100);

    // Recording end time.
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}

void test_clock(){
    //clock() : clock() returns the number of clock ticks elapsed since the program was launched.
    /* clock_t clock(void) returns the number of clock ticks
       elapsed since the program was launched.To get the number
       of seconds used by the CPU, you will need to divide by
       CLOCKS_PER_SEC.where CLOCKS_PER_SEC is 1000000 on typical
       32 bit system.  */
    clock_t start, end;

    /* Recording the starting clock tick.*/
    start = clock();
    usleep(100);

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "test_clock Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}

// A sample function whose time taken to
// be measured
void fun()
{
    for (int i=0; i<10; i++)
    {
    }
}

void test_gettime(){
    //gettimeofday() : The function gettimeofday() can get the time as well as timezone.
    /* The function gettimeofday() can get the time as
       well as timezone.
       int gettimeofday(struct timeval *tv, struct timezone *tz);
      The tv argument is a struct timeval and gives the
      number of seconds and micro seconds since the Epoch.
      struct timeval {
               time_t      tv_sec;     // seconds
               suseconds_t tv_usec;    // microseconds
           };    */
    struct timeval start, end;

    // start timer.
    gettimeofday(&start, NULL);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    //fun();
    //usleep(10);
    struct timespec tim;
    tim.tv_sec = 0;
    tim.tv_nsec = 100000;
    nanosleep(&tim,NULL);
    // stop timer.
    gettimeofday(&end, NULL);

    // Calculating total time taken by the program.
    double time_taken;

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec -
                                start.tv_usec));

    cout << "test_gettime Time taken by program is : " << fixed
         << time_taken << setprecision(6);
    cout << " usec" << endl;
}

void test_clock_gettime(){
    //clock_gettime() : The clock_gettime() function gets the current time of the clock specified by clock_id, and puts it into the buffer pointed to by tp.
    /* int clock_gettime( clockid_t clock_id, struct
     timespec *tp ); The clock_gettime() function gets
     the current time of the clock specified by clock_id,
     and puts it into the buffer  pointed to by tp.tp
     parameter points to a structure containing
     atleast the following members:
     struct timespec {
               time_t   tv_sec;        // seconds
               long     tv_nsec;       // nanoseconds
           };
    clock id = CLOCK_REALTIME, CLOCK_PROCESS_CPUTIME_ID,
               CLOCK_MONOTONIC ...etc
    CLOCK_REALTIME : clock  that  measures real (i.e., wall-clock) time.
    CLOCK_PROCESS_CPUTIME_ID : High-resolution per-process timer
                               from the CPU.
    CLOCK_MONOTONIC : High resolution timer that is unaffected
                      by system date changes (e.g. NTP daemons).  */
    struct timespec start, end;

    // start timer.
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    // clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_MONOTONIC, &start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

   usleep(100);

    // stop timer.
    // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    // clock_gettime(CLOCK_REALTIME, &end);
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculating total time taken by the program.
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-3;

    cout << "test_clock_gettime Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " usec" << endl;
}

void test_chrono(){
    auto start = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    usleep(100);
    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-3;

    cout << "test_chrono Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " usec" << endl;

}