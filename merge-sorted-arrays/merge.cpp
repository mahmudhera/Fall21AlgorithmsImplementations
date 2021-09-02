#include <stdio.h>
#include <stdlib.h>

const int * merge_sorted_arrays(const int *A, const int m, const int *B, const int n) {
    int * C = new int [m+n];
    int kA = 0;
    int kB = 0;
    for (int k = 0; k < m+n; k++) {
        if (A[kA] <= B[kB]) {
            C[k] = A[kA++];
        } else {
            C[k] = B[kB++];
        }
    }
    return C;
}

void print_array(const int * arr, const int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {1, 3, 6, 8, 10};
    int B[] = {2, 4, 5, 7, 13, 14, 15};
    const int * merged_array = merge_sorted_arrays(A, 5, B, 7);
    print_array (merged_array, 12);
    free((void *)merged_array);
    return 0;
}
