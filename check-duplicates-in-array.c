#include <stdio.h>

int main()
{
    int n, i, j, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                found = 1;
                break;
            }
        }
        if(found)
            break;
    }

    if(found)
        printf("Duplicates found");
    else
        printf("No duplicates");

    return 0;
}
/*
OUTPUT
Enter the number of elements: 5
Enter the elements:
5 8 2 5 9
Duplicates found
*/
