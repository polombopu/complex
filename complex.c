#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "complex.h" 

void read_comp(Complex *a, double x, double y) {
    a->first = x;
    a->second = y;
}

void print_comp(Complex *a) {
    if(a->first == 0 && a->second == 0){
        printf("0\n");
    }
    if(a->first == 0){
        printf("The complex number is: (%lf)i \n", a->second);
    }
    if(a->second == 0){
        printf("The complex number is: (%lf) \n", a->first);
    }
    printf("The complex number is: (%lf) + (%lf)i \n", a->first, a->second);
}

void add_comp(Complex *a, Complex *b) {
    Complex temp;
    temp.first = a->first + b->first;
    temp.second = a->second + b->second;
    print_comp(&temp);
}

void sub_comp(Complex *a, Complex *b) {
    Complex temp;
    temp.first = a->first - b->first;
    temp.second = a->second - b->second;
    print_comp(&temp);

}

void mult_comp_real(Complex *a, double real) {
    Complex temp;
    temp.first = ((a->first) * real);
    temp.second = ((a->second) * real);
    print_comp(&temp);
}

void mult_comp_img(Complex *a, double real) {
    Complex temp;
    temp.first = -(a->first * real);
    temp.second = -(a->second * real);
    print_comp(&temp);    
}

void mult_comp_comp(Complex *a, Complex *b) {
    Complex temp;
    temp.first = (a->first * b->first) - (a->second * b->second);
    temp.second = (a->first * b->second) + (a->second * b->first);
    print_comp(&temp);
}

void abs_comp(Complex *a) {
    printf("The number is: %.2f \n", sqrt((a->first * a->first) + (a->second * a->second)));
}
