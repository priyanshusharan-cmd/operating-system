#include <stdio.h>

int linear(int a[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }
    return -1;
}

int binary(int a[], int n, int key)
{
    int l = 0, r = n - 1;

    while(l <= r)
    {
        int m = l + (r - l) / 2;

        if(a[m] == key)
            return m;
        else if(a[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
    int n, key, choice, res;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    printf("1. Linear Search\n2. Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        res = linear(a, n, key);
    else if(choice == 2)
        res = binary(a, n, key);
    else
    {
        printf("Invalid choice\n");
        return 0;
    }

    if(res == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", res);

    return 0;
}

/*
OUTPUT
Enter number of elements: 4
Enter elements:
2 4 6 9
Enter key to search: 6
Enter choice: 1
Element found at index 2
*/
