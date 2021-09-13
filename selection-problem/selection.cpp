#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(const int * arr, const int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int selection(int *, int, int);

int find_pivot(int *arr, int n) {
    if (n == 1) {
        return arr[0];
    }

    int num_elements = ceil(1.0*n/5);
    int *array_of_medians = new int [num_elements];
    int arr_medians_index = 0;

    for (int i = 0; i < n; i+=5) {
        int smallest = 999999, second_smallest = 99999, median = 99999;
        for (int j = 0; j < 5 && i+j < n; j++) {
            if (arr[i+j] < smallest) {
                smallest = arr[i+j];
            }
        }
        for (int j = 0; j < 5 && i+j < n; j++) {
            if (arr[i+j] > smallest && arr[i+j] < second_smallest) {
                second_smallest = arr[i+j];
            }
        }
        for (int j = 0; j < 5 && i+j < n; j++) {
            if (arr[i+j] > second_smallest && arr[i+j] < median) {
                median = arr[i+j];
            }
        }
        int ans = median;
        if (median == 999999) ans = second_smallest;
        if (second_smallest == 999999) ans = smallest;
        array_of_medians[arr_medians_index++] = ans;
    }

    print_array(arr, n);
    print_array(array_of_medians, num_elements);

    int ret_value = selection(array_of_medians, num_elements, num_elements/2);
    delete [] array_of_medians;
    return ret_value;
}

int selection(int * arr, int n, int p) {
    int pivot = find_pivot(arr, n);

    int * a_left = new int [n];
    int * a_right = new int [n];
    int a_left_index = 0;
    int a_right_index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < pivot) {
            a_left[a_left_index++] = arr[i];
        }
        if (arr[i] > pivot) {
            a_right[a_right_index++] = arr[i];
        }
    }

    int a_left_size = a_left_index;
    int a_right_size = a_right_index;

    int ret_value;
    if (p < a_left_size-1) {
        ret_value = selection(a_left, a_left_size, p);
    } else if (p == a_left_size) {
        ret_value = pivot;
    } else {
        ret_value = selection(a_right, a_right_size, p-a_left_size-1);
    }

    delete [] a_left;
    delete [] a_right;

    return ret_value;
}



int main() {
    int A[] = {4, 2, 8, 5, 90, 32, 14, -23, 3, 27, 45, 33};
    int answer = selection(A, 12, 7);
    printf("%d", answer);
    return 0;
}
