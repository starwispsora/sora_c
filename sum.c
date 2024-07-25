#include <stdio.h>

int main(void)
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
    }
    printf("Sum of numbers from 1 to 100 is: %d\n", sum);

    int num;
    printf("Input num: ");
    scanf("%d", &num);
    printf("%d is a %s number\n", num, (num > 0) ? "positive" : (num == 0) ? "zero" : "negative");

    return 0;
}