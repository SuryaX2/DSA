// insertion sort
#include <stdio.h>
void insertionsort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
int main()
{
    int a[10], i, j, n;
    printf("Enter the Range=");
    scanf("%d", &n);
    printf("Enter the No.= ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    insertionsort(a, n);
    printf("\nSorted ArrayList : ");
    for (j = 0; j < n; j++)
        printf("%d ", a[j]);
    return 0;
}