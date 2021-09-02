#include <stdio.h>
#include <stdlib.h>

void print_array(const int * arr, const int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int * merge_sorted_arrays(const int *A, const int m, const int *B, const int n) {
    int * C = new int [m+n];
    int kA = 0;
    int kB = 0;
    for (int k = 0; k < m+n; k++) {
        if (kA < m && (A[kA] < B[kB] || kB == n)) {
            C[k] = A[kA++];
        } else {
            C[k] = B[kB++];
        }
    }
    return C;
}

int * merge_sort(const int * A, int n) {
    if (n == 1) {
        int * single_value = new int[1];
        single_value[0] = A[0];
        return single_value;
    }

    int nMid = n/2;
    int * A_low = new int [nMid];
    int * A_high = new int [n - nMid];

    for (int i = 0; i < nMid; i++) {
        A_low[i] = A[i];
    }
    for (int i = nMid; i < n; i++) {
        A_high[i-nMid] = A[i];
    }

    int * A_low_sorted = merge_sort(A_low, nMid);
    int * A_high_sorted = merge_sort(A_high, n-nMid);

    //print_array(A_low_sorted, nMid);
    //print_array(A_high_sorted, n-nMid);

    delete[] A_low;
    delete[] A_high;

    int * A_sorted = merge_sorted_arrays(A_low_sorted, nMid, A_high_sorted, n-nMid);

    //print_array(A_sorted, n);

    delete[] A_low_sorted;
    delete[] A_high_sorted;

    return A_sorted;

}

int main() {
    int A[] = {4, 2, 8, 5, 3, 90, 32, 14, -23, 3, 27, 2, 5, 8, 45, 33};
    int * sorted = merge_sort(A, 16);
    print_array (sorted, 16);
    delete[] sorted;
    return 0;
}
