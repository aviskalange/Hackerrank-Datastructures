n,m=map(int,input().split())
ar=[0 for i in range(n)]
max=0
for i in range(m):
	a,b,k=map(int,input().split())
	for j in range(a-1,b):
		ar[j]=ar[j]+k
		if ar[j]>max:
			max=ar[j]

print(max)
