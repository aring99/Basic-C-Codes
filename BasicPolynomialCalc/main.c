#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIZE 100
int main()
{
//    double a= 2, b =3;
//double d= pow( a,  b);
//printf("%f",d);
    int arr_coeff[SIZE];
    int status =1;
    double arr_result = 0.0;
    double actuall_result = 0.0;
    int degree = 0;
    int coeff_holder =0;
    int temp_x = 0;
    double x= 0.0;

    printf("Degree of polynomial \n");
    scanf("%d",&degree);
    printf("Coefficients of polynomial:\n");
    for(int t = 0; t<= degree; t++)
    {
        printf("a");
        printf("%d: \n",t);
        scanf("%d",&coeff_holder);
        arr_coeff[t]=coeff_holder;


    }
    while(status == 1)
    { temp_x = 0;
        printf("Value of x: \n");
        scanf("%d",&temp_x);
        double x = temp_x;
        printf("p(");
        printf("%.2f", x);

        printf(") = ");
        for(int c = 0; c<=degree; c++)
        {
            double result = ( arr_coeff[c])* (pow(x,  c));
            actuall_result = actuall_result+ result;
            //double pow(double base, double exponent);
        }
        printf("%.2f \n", actuall_result);
        printf("Do you want to continue? (1/0):\n");
        scanf("%d",&status);
          arr_result = 0.0;
     actuall_result = 0.0;
     temp_x = 0;
     x= 0.0;
    }
}
