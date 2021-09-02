This algorithm will merge two sorted arrays into another sorted array.

### Input
A[1..n], B[1..m]
### Output
C[1..m+n]

### Algorithm
```
kA = kB = k = 1
A[n+1] = B[m+1] = M(very large)
while k <= m+n:
	if A[kA] <= B[kB]:
		C[k] = A[kA]
		kA += 1
	else:
		C[k] = B[kB]
		kB += 1
	k += 1
return C
```

### Running time
O(m+n)

