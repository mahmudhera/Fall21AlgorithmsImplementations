This algorithm will perform merge-sort on an unsorted array

### Input
A[1..n]
### Output
A'[1..n], the sorted version

### Algorithm
```
function MergeSort(A[1..n])
nMid = n/2
A_low = A[1 .. nMid]
A_high = A[nMid+1 .. n]
A_low_sorted = MergeSort(A[1 .. nMid])
A_high_sorted = MergeSort(A[nMid+1 .. n])
A_sorted = Merge(A_low_sorted, A_high_sorted)
return A_sorted
```

### Running time
Recurrence: T(n) = 2 T(n/2) + O(n)
SOlving: O(n log n)

