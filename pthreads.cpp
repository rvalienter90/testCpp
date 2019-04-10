//
// Created by nsl on 4/10/19.
//


#include "pthreads.h"
unsigned int timeWindow_read=2000000;

void *print_test(void *threadid){
    usleep(1000000);
    cout << "Hello World! Thread, "<< endl;
}

void *PrintHello(void *threadid) {
    long tid;
    tid = (long)threadid;
    usleep(3000000);
    cout << "Hello World! Thread ID, " << tid << endl;
    pthread_exit(NULL);
}

void test_pthread(){
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;

    for( i = 0; i < NUM_THREADS; i++ ) {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void test_pthread0(){

    pthread_t mythread;
    int i=0;
    cout << "main() : creating thread, " << i << endl;
    pthread_create(&mythread,NULL, print_test,(void *)i);
}

void test_pthread_sleep(){
    //using namespace std::chrono_literals;
    std::cout << "Hello waiter\n" << std::flush;
    auto start = std::chrono::high_resolution_clock::now();
    sleep(2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "Waited " << elapsed.count() << " ms\n";
}



void test_pthread_sleep_recurrent(){
    pthread_t mythread;
    int i=0;
    cout << "main() : creating thread, " << i << endl;
    pthread_create(&mythread,NULL, recurrent_function,(void *)i);
}

void *recurrent_function(void *threadid){
    int num=0;

        while(true)
        {
            num++;
            auto startt = std::chrono::high_resolution_clock::now();

            auto start = std::chrono::steady_clock::now();
            auto end = std::chrono::steady_clock::now();
            //auto elapsed = end - start;
            std::chrono::duration<double, std::micro> elapsed= end - start;
            unsigned int timeToWait = timeWindow_read - int(elapsed.count());
            if(timeToWait > 0)
            {
                cout<<"Waiting "<<timeToWait<<endl;
                usleep(timeToWait);


            }

            auto endt = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> elapsedt = endt-startt;
            std::cout << "Waited " << elapsedt.count() << " ms\n";
            if (num>5)
                break;
        }
};