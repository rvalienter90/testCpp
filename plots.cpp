//
// Created by rvalienter90 on 3/30/19.
//

#include "plots.h"
namespace plt = matplotlibcpp;

void test_plot_basic(){
    plt::plot({1,3,2,4});
    plt::show();
}

void test_plot_func(){
// Prepare data.
    int n = 5000;
    std::vector<double> x(n), y(n), z(n), w(n,2);
    for(int i=0; i<n; ++i) {
        x.at(i) = i*i;
        y.at(i) = sin(2*M_PI*i/360.0);
        z.at(i) = log(i);
    }

    // Set the size of output image to 1200x780 pixels
    plt::figure_size(1200, 780);
    // Plot line from given x and y data. Color is selected automatically.
    plt::plot(x, y);
    // Plot a red dashed line from given x and y data.
    plt::plot(x, w,"r--");
    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot("log(x)", x, z);
    // Set x-axis to interval [0,1000000]
    plt::xlim(0, 1000*1000);
    // Add graph title
    plt::title("Sample figure");
    // Enable legend.
    plt::legend();
    // Save the image (file format is determined by the extension)
    plt::save("./basic.png");
}

void test_plot_func_cont(){
    // Prepare data.
    plt::ion();
    int n = 5000;
    std::vector<double> x(n), y(n), z(n), w(n,2);
    for(int i=0; i<n; ++i) {
        x.at(i) = i*i;
        y.at(i) = sin(2*M_PI*i/360.0);
        z.at(i) = log(i);
        plt::plot(x, y);
       // plt::scatter(x, y);
        plt::draw();
        plt::show();
        plt::pause(0.1);
        plt::clf();
        //sleep(1);
    }
}
void test_plot_scatter_cont(){

    // Prepare data.
    plt::ion();
    int n = 5000;
    std::vector<double> x(n), y(n), z(n), w(n,2);
    for(int i=0; i<n; ++i) {
        x.at(0) = i*i;
        y.at(0) = sin(2*M_PI*i/360.0);
        z.at(0) = log(i);
        //plt::plot(x, y);
        plt::scatter(x, y);
        plt::draw();
        plt::show();
        plt::pause(0.1);
        plt::clf();
        //sleep(1);
    }
}