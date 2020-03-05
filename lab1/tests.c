#include "funcs.h"
int int_check(linear_form lf, int n, int a[]){
    if (lf.n != n){
        return 1;
    }
    else{
        for (int i = 0; i < n; ++i){
            if (((int*)lf.c)[i] != a[i]){
                return 1;
            }
        }
        return  0;
    }
}
int float_check(linear_form lf, int n, float a[]) {
    if (lf.n != n) {
        return 1;
    } else {
        for (int i = 0; i < n; ++i) {
            if (((float *) lf.c)[i] != a[i]) {
                return 1;
            }
        }
        return 0;
    }
}




int main(){
    int check;
    int int_scalar = -1;
    float float_scalar = 2;

    int int_true_add[8] = {2, 4, 0, 8, 10, 0, 0, 10};
    float float_true_add[8] = {-2, 0, 2, 1, 2, 0.5, 0.25, 0.125};
    int int_true_sub[8] = {0, 0, 0, 0, 0, 0, 0, -10};
    float float_true_sub[8] = {0, 0, 0, 0, 0, -0.5, -0.25, -0.125};
    int int_true_scalar_lf4[5] = {-1, -2, 0, -4, -5};
    float float_true_scalar_lf4[5] = {-2, 0, 2, 1, 2};
    int int_true_scalar_lf7[8] = {-1 ,-2, 0, -4, -5, 0, 0, -10};
    float float_true_scalar_lf7[8] = {-2, 0, 2, 1, 2, 1, 0.5, 0.25};

    int int_a4[5] = {1, 2, 0, 4, 5};
    int int_a7[8] = {1, 2, 0, 4, 5, 0, 0, 10};
    float float_a4[5] = {-1, 0, 1, 0.5, 1};
    float float_a7[8] = {-1, 0, 1, 0.5, 1 , 0.5, 0.25, 0.125};
    linear_form int_lf4, int_lf7, float_lf4, float_lf7;
    linear_form int_result_lf;
    linear_form float_result_lf;
    int_lf4.n = 5;
    float_lf4.n = 5;
    int_lf7.n = 8;
    float_lf7.n = 8;
    int_lf4.c = int_a4;
    int_lf7.c = int_a7;
    float_lf4.c = float_a4;
    float_lf7.c = float_a7;
    int_lf4.eltype = 0;
    int_lf7.eltype = 0;
    float_lf4.eltype = 1;
    float_lf7.eltype = 1;
    int_result_lf = add_lf(int_lf4, int_lf7);
    float_result_lf = add_lf(float_lf4, float_lf7);
    check = int_check(int_result_lf, 8, int_true_add);
    if (check) printf("1st test wasnt passed. \n"); else printf("1st test was successful!\n");
    check  = float_check(float_result_lf, 8, float_true_add);
    if (check) printf("2nd test wasnt passed. \n"); else printf("2nd test was successful!\n");
    int_result_lf = sub_lf(int_lf4, int_lf7);
    float_result_lf = sub_lf(float_lf4, float_lf7);
    check  = int_check(int_result_lf, 8, int_true_sub);
    if (check) printf("3d test wasnt passed. \n"); else printf("3d test was successful!\n");
    check  = float_check(float_result_lf, 8, float_true_sub);
    if (check) printf("4d test wasnt passed. \n"); else printf("4d test was successful!\n");
    scalar_multiply_lf(&int_lf4, &int_scalar);
    scalar_multiply_lf(&int_lf7, &int_scalar);
    scalar_multiply_lf(&float_lf4, &float_scalar);
    scalar_multiply_lf(&float_lf7, &float_scalar);
    check  = int_check(int_lf4, 5, int_true_scalar_lf4);
    if (check) printf("5d test wasnt passed. \n"); else printf("5d test was successful!\n");
    check  = int_check(int_lf7, 8, int_true_scalar_lf7);
    if (check) printf("6d test wasnt passed. \n"); else printf("6d test was successful!\n");
    check  = float_check(float_lf4, 5, float_true_scalar_lf4);
    if (check) printf("7d test wasnt passed. \n"); else printf("7d test was successful!\n");
    check  = float_check(float_lf7, 8, float_true_scalar_lf7);
    if (check) printf("8d test wasnt passed. \n"); else printf("8d test was successful!\n");
    return 0;
}

