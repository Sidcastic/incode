#include<stdio.h>
int main() 
{
    int i = 0, j = 0, k;
    for (i = 0; i < 17; i++)
    {
        for (k = 16; k >= i; k--)
        {
            printf(" ");    
        }
        for (j = 0; j <= (i); j++)
        {
            printf("* ");
        }
        printf("\n");   
    }
    return 0;
}