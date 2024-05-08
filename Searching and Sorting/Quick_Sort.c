#include <stdio.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int partition(int a[], int low, int high)
{
    int pivot = a[low], i = low + 1, j = high, temp;
    do
    {
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quickSort(int a[], int low, int high)
{
    int j; // Index of pivot after partition
    if (low < high)
    {
        j = partition(a, low, high);
        quickSort(a, low, j - 1);  // sort left subarray
        quickSort(a, j + 1, high); // sort right subarray
    }
}
int main()
{
    int i, n;
    printf("\nEnter Range : ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter Value : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nArrayList : ");
    printArray(a, n);
    quickSort(a, 0, n - 1);
    printf("\nSorted ArrayList : ");
    printArray(a, n);
    return 0;
}