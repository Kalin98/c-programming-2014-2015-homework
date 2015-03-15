#include <stdio.h>

int main()
{
    int array[100], c, n;
    printf("Enter the number of elements in the array: \n");
    scanf(" %d", &n);
    printf("Enter %d elements: \n", n);
    for (c = 0; c < n; c++)
        scanf(" %d", &array[c]);
    for (c = 0; c <= n; c++)
        printf(" %d", array[c]);
    return 0;
}
