#include<stdio.h>
int largest(int a[], int n)
{
    int max = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(max < a[i])
            max = a[i];
    }
    return max;
}
void RadixSort(int a[], int n)
{
    int b[10][10], b_c[10];
    int i, j, k, r, NOP=0, div=1, max, p;
    max = largest(a, n);
    printf("The large element %d\n",max);
    for(;max > 0;max/=10)
        NOP++;
    for(p = 0; p < NOP; p++)
    {
        for(i = 0; i < 10; i++)
            b_c[i] = 0;
        for(i = 0; i < n; i++)
        {
            r = (a[i] / div) % 10;
            b[r][b_c[r]] = a[i];
            b_c[r] += 1;
        }
        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < b_c[k]; j++,i++)
                a[i] = b[k][j];
        }
        div *= 10;
        for(i = 0; i < n; i++)
            printf("%d  ",a[i]);
        printf("\n");
    }
}
int main()
{
    int i, n, a[10];
    printf("Enter the number of elements :: ");
    scanf("%d",&n);
    printf("Enter the elements :: ");
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    RadixSort(a,n);
    printf("The sorted elements are ::  ");
    for(i = 0; i < n; i++)
        printf("%d  ",a[i]);
    printf("\n");
    return 0;
}