#include <stdio.h>
void bubble(int *a, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int a[50], i, n, k = 1, j, temp;
    printf("Enter Range : ");
    scanf("%d", &n);
    printf("Enter Value : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubble(a, n);
    printf("\nSorted ArrayList : ");
    for (j = 0; j < n; j++)
        printf("%d ", a[j]);
    return 0;
}
