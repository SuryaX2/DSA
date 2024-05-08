#include <stdio.h>
void Search(int *a, int n, int key)
{
    int beg = 0, end = n - 1;
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (a[mid] == key)
        {
            printf("\n%d Found ! at position %d", key, mid + 1);
            break;
        }
        else if (a[mid] < key)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    if (beg > end)
        printf("\nElement Not found !");
}
int main()
{
    int n, key;
    printf("\nEnter number of elements:");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter element :");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter element you want to find:");
    scanf("%d", &key);
    Search(a, n, key);
    return 0;
}