#define MAX 80

typedef struct Complex {
    double first;
    double second;
}Complex;

void read_comp(Complex *a, double x, double y);
void print_comp(Complex *a);
void add_comp(Complex *a, Complex *b);
void sub_comp(Complex *a, Complex *b);
void mult_comp_real(Complex *a, double real); 
void mult_comp_img(Complex *a, double real);
void mult_comp_comp(Complex *a, Complex *b);
void abs_comp(Complex *a);
