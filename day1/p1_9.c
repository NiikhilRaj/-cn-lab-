#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char *argv[])
{
    int a, b;
    
    if(argc != 3)
    {
        printf("Please enter exactly 2 numbers\n");
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }
    
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    
    printf("Before swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    swap(&a, &b);
    
    printf("\nAfter swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    return 0;
}