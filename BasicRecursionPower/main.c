#include <stdio.h>

int divisorPower(int num, int d)
{ int recursion_counter = 0;
    int recursion_starter = num%d;
    if(recursion_starter == 0){
            recursion_counter = recursion_counter+1;
        return divisorPower(num / d, d)+recursion_counter;
    }

    return 0;

}
int main()
{
    int num;
    int d;
    int p;

    printf("Enter number> ");
    scanf("%d", &num);
    printf("Enter divisor> ");
    scanf("%d", &d);
    p = divisorPower(num, d);
    printf("%d power of %d divides %d evenly.", p, d, num);

    return 0;
}
