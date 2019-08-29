//
// Created by rvali on 8/29/2019.
//
#include <iostream>
struct my_struct{
    int a;
    float b;
};
typedef my_struct MY_STRUCT;

class my_object{
public:
    int a;
    float b;

};



void test_mem(){
    //MY_STRUCT my_truct_array[2][2][5];
    my_object my_truct_array[2][2][5];
    my_truct_array[0][0][0].a=1;
    my_truct_array[0][0][0].b=10;
    std::cout<<my_truct_array[0][0][0].a<<std::endl;


}

typedef struct {
    int i;
} test;

void test_mem2(){
    // A two dimensional array with each element is a test
    test t1[20][20];
    //That will declare a 2-dimensional array of test of size 20 x 20. There's no need to use malloc.
    //
    //If you want to dynamically allocate your array you can do this:

    test **t = (test **)malloc(20 * sizeof(test *));
    int i=0;
    for (i = 0; i < 20; ++i)
        t[i] = (test *)malloc(20 * sizeof(test));

    //A two dimensional array with each element has a pointer to test
    test* t3[20][20];
    for (int i=0; i < 20; i++){
        for (int j=0; j < 20; j++){
            t3[i][j] =(test *)malloc(sizeof(test));
        }
    }

}

