n, k = map(int, input().split())
arr = [int(j) for j in input().split()]
if k>= n:
	print(0)
else:
	arr.sort(reverse=True)
	print(sum(arr[k:]))