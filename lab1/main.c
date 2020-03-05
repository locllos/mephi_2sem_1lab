#include "funcs.h"

void input_func(){
    int iter = 0;
    int n, sum;
    int eltype;
    int input, lf1_exist = 0, lf2_exist = 0;
    linear_form lf1;
    linear_form lf2;
    linear_form result_lf;
    printf("If you want to work with int type - input 0, else if float type - input 1.\n Input: ");
    scanf(("%d"),&eltype);
    printf("\nYou can use 2 linear forms.\n");
    while (1) {
        if (iter%10 == 0) {
            printf("If you want: \n");
            printf("to input or update first linear form, input 11. \n");
            printf("to input or update second linear form, input 12. \n");
            printf("to add first linear form and second linear form, input 2.\n");
            printf("to subtract first linear form from second linear form, input 31.\n");
            printf("to subtract second linear form from first linear form, input 32.\n");
            printf("to multiply first linear form on scalar, input 41.\n");
            printf("to multiply second linear form on scalar, input 42.\n");
            printf("to see first linear form, input 51.\n");
            printf("to see first linear form, input 52.\n");
            printf("to substitute value in 1st linear form, input 61\n");
            printf("to substitute value in 2nd linear form, input 62\n");
            printf("to exit, input 0.\n");
        }
        printf("Input: ");
        scanf("%d", &input);
        printf("\n");
        switch (input) {
            case 11:
                printf("Input amount of variables.\nInput: ");
                scanf("%d", &n);
                lf1 = create_lf(eltype, n);
                lf1_exist = 1;
                break;
            case 12:
                printf("Input amount of variables.\nInput: ");
                scanf("%d", &n);
                lf2 = create_lf(eltype, n);
                lf2_exist = 1;
                break;
            case 2:
                if (lf1_exist * lf2_exist) {
                    result_lf = add_lf(lf1, lf2);
                    printf("Addition was successful!\n");
                    show_lf(result_lf);
                } else {
                    printf("First or second linear form does not exist! \n");
                }
                break;
            case 31:
                if (lf1_exist * lf2_exist) {
                    result_lf = sub_lf(lf1, lf2);
                    printf("Substruction was successful!\n");
                    show_lf(result_lf);
                } else {
                    printf("First or second linear form does not exist! \n");
                }
                break;
            case 32:
                if (lf1_exist * lf2_exist) {
                    result_lf = sub_lf(lf2, lf1);
                    printf("Substruction was successful!\n");
                    show_lf(result_lf);
                } else {
                    printf("First or second linear form does not exist! \n");
                }
                break;
            case 41:
                if (lf1_exist) {
                    printf("Input a number. Scalar = ");
                    if (eltype == 0){
                        int scalar;
                        scanf("%d", &scalar);
                        scalar_multiply_lf(&lf1, &scalar);
                        show_lf(lf1);
                    }
                    else if (eltype == 1){
                        float scalar;
                        scanf("%f", &scalar);
                        scalar_multiply_lf(&lf1, &scalar);
                        show_lf(lf1);
                    }
                }
                else{
                    printf("First linear form does not exist!\n");
                }
                break;
            case 42:
                if (lf2_exist) {
                    printf("Input a number. Scalar = ");
                    if (eltype == 0){
                        int scalar;
                        scanf("%d", &scalar);
                        scalar_multiply_lf(&lf2, &scalar);
                        show_lf(lf2);
                    }
                    else if (eltype == 1){
                        float scalar;
                        scanf("%f", &scalar);
                        scalar_multiply_lf(&lf2, &scalar);
                        show_lf(lf2);
                    }
                }
                else{
                    printf("Second linear form does not exist!\n");
                }
                break;
            case 51:
                if (lf1_exist) {
                    show_lf(lf1);
                }
                else{
                    printf("First linear form does not exist!\n");
                };
                break;
            case 52:
                if (lf2_exist) {
                    show_lf(lf2);
                }
                else{
                    printf("Second linear form does not exist!\n");
                }
                break;
            case 61:
                if (lf1_exist) {substitution(lf1);}
                else {(printf("First linear form does not exist!\n"));};
                break;
            case 62:
                if (lf2_exist) {substitution(lf2);}
                else {(printf("Second linear form does not exist!\n"));};
                break;
            case 0:
                break;
            default:
                printf("The command does not exist. \n");
                break;
        }
        if (input==0){
            printf("Exit...");
            break;
        }
        input = -1;
        ++iter;
    }
}

int main()
{
    input_func();
}

