#include <stdio.h>

void display(int arr[], int n)
{
    int i;
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}

void merge(int arr[], int mid, int low, int high)
{
    int i, j, k, temp[50];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
        arr[i] = temp[i];
    return;
}

void merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
    return;
}

int main()
{
    int arr[50], size, i;
    printf("Enter the size of the array:");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    merge_sort(arr, 0, size - 1);
    display(arr, size);
    return 0;
}