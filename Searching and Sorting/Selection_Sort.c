// selection sort
#include <stdio.h>
void selection(int *a, int n)
{
    int i, j, temp, min;
    // selection
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] < a[j])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main()
{
    int a[100], n, i, j;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    selection(a, n);
    printf("\nSorted list in ascending order:\n");
    for (j = 0; j < n; j++)
        printf("%d ", a[j]);
    return 0;
}