#include <stdlib.h>
#include <stdio.h>

typedef struct linear_form{
    int eltype;
    int n;
    void* c;
} linear_form;

linear_form create_lf(int eltype, int n) {
    linear_form lf;
    n++; //Так как у нас, вообще говоря, есть свободный коэффициент
    lf.eltype = eltype;
    lf.n = n;
    printf("Input coeffs near X\n");
    if (eltype == 0) {
        int temp;
        lf.c = (int*)calloc(n, sizeof(int)); //Я знаю, что лучше вместо int использовать typeof()
        for (int i = 0; i < n; ++i) {
            ((int*)lf.c)[i] = 0;
            if (i == 0) {
                printf("C%d, where C%d = ", i, i, i);
            } else {
                printf("C%d*x%d, where C%d = ", i, i, i);
            }
            scanf("%d", &(temp));
            ((int*)lf.c)[i] = temp;
        }
    }
    else if (eltype == 1){
        float temp;
        lf.c = (float*)calloc(n, sizeof(float)); //Я знаю, что лучше вместо float использовать typeof()
        for (int i = 0; i < n; ++i) {
            ((float*)lf.c)[i] = 0;
            if (i == 0) {
                printf("C%d, where C%d = ", i, i);

            } else {
                printf("C%d*x%d, where C%d = ", i, i, i);
            }
            scanf("%f", &(temp));
            ((float*)lf.c)[i] = temp;
        }
    }
    if (n>0) printf("Creating was successful!\n");
    return lf;
}
linear_form add_lf(linear_form lf1, linear_form lf2) {
    int eltype = (lf1).eltype;
    int min_n = (lf1).n > (lf2).n ? (lf2).n : (lf1).n;
    int max_n = (lf1).n < (lf2).n ? (lf2).n : (lf1).n;
    linear_form result_lf;
    result_lf.n = max_n;
    result_lf.eltype = eltype;
    if (eltype == 0) {
        result_lf.c = (int*)calloc(max_n, sizeof(int));
        for (int i = 0; i < min_n; ++i) {
            ((int*) result_lf.c)[i] = ((int*)lf1.c)[i] + ((int*)lf2.c)[i];
        }
        for (int i = min_n; i < max_n; ++i) {
            ((int*) result_lf.c)[i] = (int*)(lf2).n < (int*)lf1.n ? ((int*)lf1.c)[i] : ((int*)lf2.c)[i];
        }
    }
    else if (eltype == 1){
        result_lf.c = (float*)calloc(max_n, sizeof(float));
        for (int i = 0; i < min_n; ++i) {
            ((float*) result_lf.c)[i] = ((float*)lf1.c)[i] + ((float*)lf2.c)[i];
        }
        for (int i = min_n; i < max_n; ++i) {
            ((float*) result_lf.c)[i] = (float*)lf2.n < (float*)lf1.n ? ((float*)lf1.c)[i] : ((float*)lf2.c)[i];
        }
    }
    return result_lf;
}
linear_form sub_lf(linear_form lf1, linear_form lf2) {
    int min_n = lf1.n > lf2.n ? lf2.n : lf1.n;
    int max_n = lf1.n < lf2.n ? lf2.n : lf1.n;
    linear_form result_lf;
    result_lf.eltype = lf1.eltype;
    result_lf.n = max_n;
    if (result_lf.eltype == 0) {
        result_lf.c = (int*)calloc(max_n, sizeof(int));
        for (int i = 0; i < min_n; ++i) {
            ((int*)result_lf.c)[i] = ((int*)lf1.c)[i] - ((int*)lf2.c)[i];
        }
        for (int i = min_n; i < max_n; ++i) {
            ((int*)result_lf.c)[i] = (int*)lf2.n < (int*)lf1.n ? ((int*)lf1.c)[i] : - ((int*)lf2.c)[i];
        }
    }
    else if (result_lf.eltype == 1){
        result_lf.c = (float*)calloc(max_n, sizeof(float));
        for (int i = 0; i < min_n; ++i) {
            ((float*)result_lf.c)[i] = ((float*)lf1.c)[i] - ((float*)lf2.c)[i];
        }
        for (int i = min_n; i < max_n; ++i) {
            ((float*)result_lf.c)[i] = (float*)lf2.n < (float*)lf1.n ? ((float*)lf1.c)[i] : - ((float*)lf2.c)[i];
        }
    }
    return result_lf;
}

void scalar_multiply_lf(linear_form* lf, void* scalar) {
    if ((*lf).eltype == 0) {
        for (int i = 0; i < (*lf).n; ++i) {
            (((int *) (*lf).c)[i]) *= (*((int*)scalar));
        }
    }
    else if (((*lf).eltype == 1)){
        for (int i = 0; i < (*lf).n; ++i) {
            (((float*) (*lf).c)[i]) *= (*((float*)scalar));
        }
    }
}

void substitution(linear_form lf){
    float x;
    if (lf.eltype == 0){
        x = (int)x;
        int sum = ((int*)lf.c)[0];
        for (int i = 1; i<lf.n; ++i){
            printf("Input x%d value.\nInput: ", i);
            scanf("%d", &x);
            sum+=x*((int*)lf.c)[i];}
        printf("Linear form from this value is %d\n", sum);
    }
    else if (lf.eltype == 1){
        float sum = ((float*)lf.c)[0];
        for (int i = 1; i<lf.n; ++i){
            printf("Input x%d value.\nInput: ", i);
            scanf("%f", &x);
            sum+=x*((float*)lf.c)[i];}
        printf("Linear form from this value is %f\n", sum);

    }
}
void show_lf(linear_form lf) {
    int n = lf.n;
    printf("Linear form: \n");
    if (lf.eltype == 0) {
        for (int i = 0; i < n; ++i) {
            if ((i != 0) && (i != n - 1) && (n != 1)) {
                printf(" + (%d)*x%d", ((int*)lf.c)[i], i);
            } else if ((i != n - 1) || (n == 1)) {
                printf("(%d)", ((int*)lf.c)[i]);
            } else {
                printf(" + (%d)*x%d.", ((int*)lf.c)[i], i);
            }
        }
    }
    else if (lf.eltype == 1){
        for (int i = 0; i < n; ++i) {
            if ((i != 0) && (i != n - 1) && (n != 1)) {
                printf(" + (%f)*x%d", ((float*)lf.c)[i], i);
            } else if ((i != n - 1) || (n == 1)) {
                printf("(%f)", ((float*)lf.c)[i]);
            } else {
                printf(" + (%f*)x%d.", ((float*)lf.c)[i], i);
            }
        }
    }
    printf("\n");
}

#ifndef UNTITLED3_HEADER_H
#define UNTITLED3_HEADER_H

#endif //UNTITLED3_HEADER_H
