### Input
A[1..n], p

Here, p is the desired percentile index which is between 1 and n (inclusive).

### Output
A number, x, which is the p-th number in the sorted list of array A

### Algorithm
```
function selection(A[1..n], p)
	pivot = find_pivot(A)
	A_left = elements of A that are < pivot
	A_right = elements of A that are > pivot
	if p <= |A_left| then
		return selection(A_left, p)
	else if p = |A_left|+1 then
		return pivot
	else
		return selection(A_right, p-|A_left|-1)
```

This algorithm uses the following routine.
```
function find_pivot(A[1..n])
	divide A into n/5 subarrays
	calculate median of each subarrays
	A'[1..n/5] = array of medians
	return selection(A'[1..n/5])
```

### Running time
TODO
