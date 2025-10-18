import math	

x, y = map(int, input().split())

a = [0]

for i in range(1,27):
	if(i%2==0):
		a.append(int(math.sqrt(10**i))-1)
	else:
		a.append(int(math.sqrt(10**i)))

def	solve(n):
	res = 0
	for i in range(1, 27):
		if n<=a[i]:
			res+=(n-a[i-1])*(i)
			break
		else:
			res+=(a[i]-a[i-1])*(i)
	return res

print(solve(y)-solve(x-1))
