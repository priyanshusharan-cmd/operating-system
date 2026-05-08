#include <stdio.h>

int main()
{
    int n, i, min, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    min = arr[0];
    pos = 0;

    for(i = 1; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            pos = i;
        }
    }

    printf("Smallest number: %d\n", min);
    printf("Position: %d\n", pos + 1);

    return 0;
}

/*
OUTPUT
Enter the number of elements: 5
Enter the elements:
4 6 8 9 10
Smallest number: 4
Position: 1
*/
