#include <stdio.h>
#include <limits.h>
void find_max_min(int arr[], int start, int end, int* max, int* min);

int main() {
    int arr[100];
    int n, i;
    int max = INT_MIN, min = INT_MAX;  
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    find_max_min(arr, 0, n - 1, &max, &min);

    printf("Maximum value in the list: %d\n", max);
    printf("Minimum value in the list: %d\n", min);

    return 0;
}


void find_max_min(int arr[], int start, int end, int* max, int* min) {
    int mid, max1, max2, min1, min2;

    if (start == end) {  
        *max = arr[start];
        *min = arr[start];
    }
    else if (end == start + 1) {  
        if (arr[start] > arr[end]) {
            *max = arr[start];
            *min = arr[end];
        }
        else {
            *max = arr[end];
            *min = arr[start];
        }
    }
    else {  
        mid = (start + end) / 2;
        find_max_min(arr, start, mid, &max1, &min1);
        find_max_min(arr, mid + 1, end, &max2, &min2);

        if (max1 > max2) {
            *max = max1;
        }
        else {
            *max = max2;
        }

        if (min1 < min2) {
            *min = min1;
        }
        else {
            *min = min2;
        }
    }
}

