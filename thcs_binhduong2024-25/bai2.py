s, n = map(int,input().split())

start = 10**(s - 1)
end = 10**s - 1

x = start+(n-start%n)

if(x<=end):
	print(x)
else:
	print(-1)